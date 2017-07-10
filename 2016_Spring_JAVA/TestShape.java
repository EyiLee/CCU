import java.util.Scanner;

public class TestShape {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Input an double number:\n");
		double param = input.nextDouble();

		Circle circle = new Circle(param);
		Square square = new Square(param);
		Triangle triangle = new Triangle(param);
		Sphere sphere = new Sphere(param);
		Cube cube = new Cube(param);
		Tetrahedron tetrahedron = new Tetrahedron(param);

		circle.display();
		square.display();
		triangle.display();
		sphere.display();
		cube.display();
		tetrahedron.display();
	}
}
