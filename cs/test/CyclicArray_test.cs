using Xunit;
using ganq.tools;
namespace CyclicArray_test;


//dotnet test --filter "FullyQualifiedName~YourNamespace.YourClassName.YourTestMethodName"

//dotnet test --filter "FullyQualifiedName~CyclicArray_test.CyclicArrayTest.TestCyclicArray"

public class CyclicArrayTest{
	[Fact]
	public void TestCyclicArray(){
		var carr = new CyclicArray<int>(4);
		var carr2 = new CyclicArray<int?>(4);

		carr.addBack(1);
		carr.addBack(2);
		carr.addBack(3);
		carr.addBack(4);
		carr.addBack(5);
		var list =  carr.toList();
		Assert.Equal(list, new List<int>{1,2,3,4});

		carr.addBackF(6);
		var list2 =  carr.toList();
		Assert.Equal(list2, new List<int>{2,3,4,6});


	}
}