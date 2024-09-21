

#include <iostream>
#include <vector>
#include <string>

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
  //virtual void update(SubjectType, void*) = 0;
};

// Subject (Orchagent) interface
class Orchagent {
public:
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
    virtual void processUpdate(const std::string& update) = 0;
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

    void notifyObservers(const std::string& message) override {
        for (auto& observer : observers) {
            observer->update(message);
        }
    }

    void processUpdate(const std::string& update) override {
        std::cout << "RouteOrch: Processing route update: " << update << std::endl;
        notifyObservers("RouteOrch: Route update processed");
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

    void notifyObservers(const std::string& message) override {
        for (auto& observer : observers) {
            observer->update(message);
        }
    }

    void processUpdate(const std::string& update) override {
        std::cout << "NeighOrch: Processing neighbor update: " << update << std::endl;
        notifyObservers("NeighOrch: Neighbor update processed");
    }
};

// Concrete Observer: Syncd
class Syncd : public IObserver {
public:
    void update(const std::string& message) override {
        std::cout << "Syncd received update: " << message << std::endl;
    }
};

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
