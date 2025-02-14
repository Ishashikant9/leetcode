abstract class Animal {
    // Abstract method (no body)
    abstract void makeSound();

    // Concrete method (common behavior for all animals)
    void eat() {
        System.out.println("This animal eats food.");
    }
}

class Dog extends Animal {
    // Providing implementation for abstract method
    @Override
    void makeSound() {
        System.out.println("Dog barks!");
    }
}

public class Main {
    public static void main(String[] args) {
        // Using abstraction
        Dog myDog = new Dog();
        myDog.makeSound(); // Output: Dog barks!
        myDog.eat();       // Output: This animal eats food.
    }
}
