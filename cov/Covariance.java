public class Covariance
{
    public static void main(String[] args)
    {
	// Review: base = derived is OK, derived = base is not
	Integer i = new Integer(13);
	Object o = i; // base = derived
	System.out.println(o.hashCode() * 5);

	/*
	Object o2 = new Object();
	Integer i2 = o2;  // needs downcast (run-time type check)
	System.out.println(i2.intValue() * 5);
	*/

	// does this work with array of base = array of derived?
	Integer[] primes = { 2, 3, 5, 7, null };

	// LEGAL!  arrays are covariant
	Object[] arr = primes;
	// but does covariance make sense?  is an Integer[] also an Object[]
	// in C++ terms: ptr to (ptr to base) = ptr to (ptr to derived)
	// is every ptr to derived also a ptr to base?
	// does ptr to derived have same capabilities as ptr to base (plus maybe some more)
	// can I do anything to an Integer reference that I can do to an Object ref?
	// NO: can assign an object ref to an Object ref but not to an Integer
	// (or, in terms of the Java arrays: can put an Object in an Object[]
	// but can't put an Object in an Integer[])

	// so why does Java have covariance?  to allow methods to work
	// on generic arrays:
	System.out.println(countNulls(primes));

	// but now this passes compile-time checks; need something to
	// prevent disaster (non-existent method) on line AAA
	arr[4] = new String("Eleven"); // run-time exception
	// (Java arrays know their element type)
	
	System.out.println(primes[4].intValue()); // AAA

	Integer[] p2 = copyArray(primes);
	// if creating array of generic type was OK, this could end
	// in disaster (see attempted implementation of copyArray below)
	System.out.println(p2[0].intValue() * p2[1].intValue());
    }

    public static <T> T[] copyArray(T[] arr)
    {
	return null;  // implement copyArray some other way since the below doesn't compile
    /**
	T[] copy = new T[arr.length]; // can't do this
	Object[] alias = copy;
	for (int i = 0; i < arr.length; i++)
	    {
		alias[i] = arr[i].toString(); // useless run-time check;
		// useless because of type erasure
	    }
	return copy;
    */
    }

    /*
    public static Object[] copyArray(Object[] arr)
    {
	Object[] copy = new Object[arr.length];
	Object[] alias = copy;
	for (int i = 0; i < arr.length; i++)
	    {
		alias[i] = arr[i].toString(); // useless run-time check;
		// useless because of type erasure
	    }
	return copy;
    }
    */

    public static int countNulls(Object[] arr)
    {
	int count = 0;
	for (Object o : arr)
	    {
		if (o == null)
		    {
			count++;
		    }
	    }
	return count;
    }
}
    
    
