/*
+-------------------------+         +------------------------+
|        Subject          |         |        Observer        |
+-------------------------+         +------------------------+
| + Attach(Observer*)     |         |                        |
| + Detach(Observer*)     |         | + Update()             |
| + Notify()              |         +------------------------+
+-------------------------+                 ^
          ^                               / \
          |                              /   \
+------------------+                 /     \
| ConcreteSubject  |                /       \
+------------------+               /         \
| + GetState()      |              /           \
| + SetState()      |             /             \
+------------------+            /               \
                                 /                 \
                                /                   \
                       +----------------+      +----------------+
                       | ConcreteObserver|      | ConcreteObserver|
                       +----------------+      +----------------+
                       |                |      |                |
                       +----------------+      +----------------+
                       | + Update()     |      | + Update()     |
                       +----------------+      +----------------+

*/

