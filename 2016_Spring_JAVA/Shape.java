public class Shape {
	private String typename;

	public Shape(String typename) {
		this.typename = typename;
	}

	public String getTypename() {
		return this.typename;
	}
}

abstract class TwoDimensionalShape extends Shape {
	private double area;

	public TwoDimensionalShape(String typename) {
		super(typename);
	}

	public abstract double getArea();

	public void display() {
		System.out.printf("Shape:%-20sArea:%f\n",this.getTypename(), this.getArea());
	}
}

class Circle extends TwoDimensionalShape {
	private double radius;

	public Circle(double radius) {
		super("Circle");
		this.radius = radius;
	}

	public double getArea() {
		return Math.PI * this.radius * this.radius;
	}
}

class Square extends TwoDimensionalShape {
	private double length;

	public Square(double length) {
		super("Square");
		this.length = length;
	}

	public double getArea() {
		return this.length * this.length;
	}
}

class Triangle extends TwoDimensionalShape {
	private double edge;

	public Triangle(double edge) {
		super("Triangle");
		this.edge = edge;
	}

	public double getArea() {
		return Math.sqrt((this.edge * 3 / 2) * (this.edge * 3 / 2 - this.edge) * (this.edge * 3 / 2 - this.edge) * (this.edge * 3 / 2 - this.edge));
	}
}

abstract class ThreeDimensionalShape extends Shape {
	public ThreeDimensionalShape(String typename) {
		super(typename);
	}

	public abstract double getArea();
	public abstract double getVolume();

	public void display() {
		System.out.printf("Shape:%-20sArea:%f\tVolume:%f\n",this.getTypename(), this.getArea(), this.getVolume());
	}
}

class Sphere extends ThreeDimensionalShape {
	private double radius;

	public Sphere(double radius) {
		super("Sphere");
		this.radius = radius;
	}

	public double getArea() {
		return 4 * Math.PI * this.radius * this.radius;
	}

	public double getVolume() {
		return 4 / 3 * Math.PI * this.radius * this.radius * this.radius;
	}
}

class Cube extends ThreeDimensionalShape {
	private double length;

	public Cube(double length) {
		super("Cube");
		this.length = length;
	}

	public double getArea() {
		return this.length * this.length * 6;
	}

	public double getVolume() {
		return this.length * this.length * this.length;
	}
}

class Tetrahedron extends ThreeDimensionalShape {
	private double edge;

	public Tetrahedron(double edge) {
		super("Tetrahedron");
		this.edge = edge;
	}

	public double getArea() {
		return Math.sqrt((this.edge * 3 / 2) * (this.edge * 3 / 2 - this.edge) * (this.edge * 3 / 2 - this.edge) * (this.edge * 3 / 2 - this.edge)) * 4;
	}

	public double getVolume() {
		return Math.sqrt(2) / 12 * this.edge * this.edge * this.edge;
	}
}
