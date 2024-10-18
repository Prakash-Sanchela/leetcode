

#include <iostream>
#include <vector>
#include <string>

struct NeighborEntry{
	IpAddress           ip_address;     // neighbor IP address
    string              alias;          // incoming interface alias
    uint32_t            vni;            // Encap VNI overlay nexthop
    MacAddress          mac_address;    // Overlay Nexthop MAC.
    LabelStack          label_stack;    // MPLS label stack
    uint32_t            weight;         // NH weight for NHGs
    string              srv6_segment;   // SRV6 segment string
    string              srv6_source;    // SRV6 source address
	sai_common_api_t    api;
	// this has Getter and setter functions 
	// Also it has overloaded comparator, ==, != operator to compare the objects 
}
ckass MACAddress{
private:
	uint8_t m_mac[6]; // 6 is 6 byte
public:
	//Getter setter also overloaded operator 
};
struct NeighborUpdate
{
    NeighborEntry entry;
    MacAddress mac;
    bool add;
};	
enum SubjectType
{
    SUBJECT_TYPE_NEXTHOP_CHANGE,
    SUBJECT_TYPE_NEIGH_CHANGE,
    SUBJECT_TYPE_FDB_CHANGE,
    SUBJECT_TYPE_LAG_MEMBER_CHANGE,
    SUBJECT_TYPE_VLAN_MEMBER_CHANGE,
    SUBJECT_TYPE_MIRROR_SESSION_CHANGE,
    SUBJECT_TYPE_INT_SESSION_CHANGE,
    SUBJECT_TYPE_PORT_CHANGE,
    SUBJECT_TYPE_BRIDGE_PORT_CHANGE,
    SUBJECT_TYPE_PORT_OPER_STATE_CHANGE,
    SUBJECT_TYPE_ISOLATION_GROUP_CHANGE,
    SUBJECT_TYPE_ISOLATION_GROUP_MEMBER_CHANGE,
    SUBJECT_TYPE_ISOLATION_GROUP_BINDING_CHANGE,
    SUBJECT_TYPE_MLAG_INTF_CHANGE,
    SUBJECT_TYPE_MLAG_ISL_CHANGE,
    SUBJECT_TYPE_FDB_FLUSH_CHANGE,
    SUBJECT_TYPE_BFD_SESSION_STATE_CHANGE
};

// Observer interface
class IObserver {
public:
  virtual void update(const std::string& message) = 0;
  virtual void update(SubjectType, void*) = 0;
};

// Subject (Orchagent) interface
class Orchagent {
public:
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notifyObservers(SubjectType type, void *ctx) = 0;
    virtual void processUpdate(SubjectType type, void *ctx) = 0;
    virtual void update(SubjectType, void *ctx) = 0;
    virtual ~Orchagent() = default;
};

// Concrete Subject: RouteOrch
class RouteOrch : public Orchagent {
private:
    std::vector<IObserver*> observers;
    
public:
    void attach(IObserver* observer) override {
        observers.push_back(observer);
    }

    void detach(IObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(SubjectType type, void *ctx) override {
        for (auto& observer : observers) {
            observer->update(SubjectType type, void *ctx);
        }
    }

    void processUpdate(SubjectType type, void *ctx) override {
        std::cout << "RouteOrch: Processing route update: " << update << std::endl;
        notifyObservers(SubjectType type, void *ctx);
    }
};

// Concrete Subject: NhOrch (Next-hop orchestrator)
class NhOrch : public Orchagent {
private:
    std::vector<IObserver*> observers;

public:
    void attach(IObserver* observer) override {
        observers.push_back(observer);
    }

    void detach(IObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(const std::string& message) override {
        for (auto& observer : observers) {
            observer->update(message);
        }
    }

    void processUpdate(const std::string& update) override {
        std::cout << "NhOrch: Processing next-hop update: " << update << std::endl;
        notifyObservers("NhOrch: Next-hop update processed");
    }
};

// Concrete Subject: NeighOrch (Neighbor orchestrator)
class NeighOrch : public Orchagent {
private:
    std::vector<IObserver*> observers;

public:
    void attach(IObserver* observer) override {
        observers.push_back(observer);
    }

    void detach(IObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(SubjectType type, void *ctx) override {
        for (auto& observer : observers) {
            observer->update(SubjectType type, void *ctx);
        }
    }

    /*void processUpdate(SubjectType type, void *ctx) override {
        std::cout << "NeighOrch: Processing neighbor update: " << update << std::endl;
        notifyObservers(SubjectType type, void *ctx);
    }*/
    void addNeighbor(NeighborContext& ctx)
    {
        NeighborUpdate update = { neighborEntry, macAddress, true };
        notifyObservers(SUBJECT_TYPE_NEIGH_CHANGE, static_cast<void *>(&update));
    }
    void removeNeighbor(NeighborContext& ctx)
    {
        
    }
};

// Concrete Observer: Syncd
class Syncd : public IObserver {
public:
    void update(SubjectType type, void *ctx) override {
        std::cout << "Syncd received update: " << message << std::endl;
        switch (type)
        {
            case SUBJECT_TYPE_FDB_CHANGE:
                status = handle_fdb(str_object_id, api, attr_count, attr_list);
                break;
            case SUBJECT_TYPE_NEIGH_CHANGE:
                status = handle_neighbor(type, ctx);
                break;
            case SUBJECT_TYPE_ROUTE_CHANGE:
                status = handle_route(str_object_id, api, attr_count, attr_list);
                break;
        }
    }
};
sai_status_t syncd::handle_neighbor(SubjectType type, void *ctx)
{
	neighborEntry *neighEntry = static_cast<neighborEntry*>(ctx);
	attr_list = neighEntry->getAttr();
	sai_neighbor_entry_api = upNeighEntry->getApi();
	
	switch (api)
    {
        case SAI_COMMON_API_CREATE:
            return m_sai->create(&neighEntry, attr_list);
			return m_sai->create_neighbor_entr(&neighEntry);

        case SAI_COMMON_API_REMOVE:
            return m_sai->remove(&neighEntry);

        case SAI_COMMON_API_SET:
            return m_sai->set(&neighEntry, attr_list);
        default:
            SWSS_LOG_THROW("no other neighbor apis implemented");
    }
}

SAI_COMMON_API_CREATE
SAI_COMMON_API_REMOVE
SAI_COMMON_API_GET
SAI_COMMON_API_SET

// Application code demonstrating APPL_DB updates
int main() {
    // Create orchestrators
    RouteOrch routeOrch;
    NhOrch nhOrch;
    NeighOrch neighOrch;

    // Create Syncd observer
    Syncd syncd;

    // Syncd subscribes to all orchestrators
    routeOrch.addObserver(&syncd);
    nhOrch.addObserver(&syncd);
    neighOrch.addObserver(&syncd);

    // Simulate updates from APPL_DB
    std::cout << "Application: Sending updates from APPL_DB...\n";

    routeOrch.processUpdate("Add route 10.0.0.0/24");
    nhOrch.processUpdate("Add next-hop 192.168.1.1");
    neighOrch.processUpdate("Add neighbor MAC for 192.168.1.1");

    return 0;
}
