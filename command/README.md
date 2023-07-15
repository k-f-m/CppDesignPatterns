# Command

The Command design pattern is a behavioral pattern that transforms a request into a standalone object that contains all the information about the request. This transformation allows us to pass requests as method arguments, delay or queue the execution of a request, and support undoable operations [1].

The Command design pattern is used to encapsulate a request as an object and pass it to an invoker, where the invoker does not know how to serve the request, but uses the encapsulated command to perform an action. This pattern is used to implement loose coupling in a request-response model [2].

## References
[1] https://refactoring.guru/design-patterns/command
[2] https://www.digitalocean.com/community/tutorials/command-design-pattern