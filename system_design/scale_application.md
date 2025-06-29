## How can we make an application scalable?
- scale means based on demands our system should respond.
- if demand increase system response should be increased and if demand decrease response should be based on that.

### There are two bottlenecks of system 
- Centralized components (centralized database)
   Single databased component handles all the incoming request 
- High latency operations

## Major 3 components to build scalable syste
### Stateless Architecture
  Stateless refers to each request from a client to a server is treated as independant transaction, containing all necessary information to understand and process the request. 
  without relaying on any stored context or session state on server. 
  Example : REST APIs, client sends authentication token and all necessary data with each HTTPS request.
  #### Advantages :
  - Easy to scale horizontally (add more servers).
  - Any server can handle any request since there's no session-specific data.
  - Since the server doesn’t store client state, server failures don’t affect ongoing user sessions.
  - Better for load balancers and distributed systems.
  
### Loose coupling 
### Asynchronous processing 


## Implement caching strategy for scalable system 
  
