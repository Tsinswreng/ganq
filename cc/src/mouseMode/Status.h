#include "common.h"
#include "impl/KeyEvent.h"
#include "tools/CyclicArray/CyclicArray.h"
#include "tools/CyclicArray/I_CyclicArray.h"
#include "IF/I_KeyEvent.h"
#include <memory>
#include <vector>
namespace _ {

namespace {
// I_CyclicArray是CyclicArray的父類、I_KeyEvent是KeyEvent的父類、an是共享指針
	using I_KeyHistory = I_CyclicArray<an<I_KeyEvent>>;
	using KeyHistory = CyclicArray<an<KeyEvent>>;
}

class Status {
public: 
	an<I_KeyHistory> history_(){return history;}

	bool isShiftDown_(){return _isShiftDown;}
	void isShiftDown_(bool v){_isShiftDown = v;};

	bool isCtrlDown_(){return _isCtrlDown;}
	void isCtrlDown_(bool v){_isCtrlDown = v;}

	bool isAltDown_(){return _isAltDown;}
	void isAltDown_(bool v){_isAltDown = v;}

	bool isMetaDown_(){return _isMetaDown;}
	void isMetaDown_(bool v){_isMetaDown = v;}

	bool isMouseMode_(){return _isMouseMode;}
	void isMouseMode_(bool v){_isMouseMode = v;}

	void test(){
		//std::make_shared<CyclicArray<an<KeyEvent>>>(16);
		// std::make_shared<std::vector<
		// 	std::shared_ptr<KeyEvent>
		// >>(10);
	}


protected:
	an<I_KeyHistory> history
		= As<I_KeyHistory>(New< //智能指針多態要用dynamic_pointer_cast
				KeyHistory
			>(16)
		)
	;

	bool _isShiftDown = false;
	bool _isCtrlDown = false;
	bool _isAltDown = false;
	bool _isMetaDown = false;
	bool _isMouseMode = false;

//No viable conversion from 'shared_ptr<CyclicArray<_::KeyEvent>>' to 'shared_ptr<I_CyclicArray<I_KeyEvent>>'clang(typecheck_nonviable_condition)
	// std::shared_ptr<I_CyclicArray<I_KeyEvent>> h 
	// 	= std::make_shared<CyclicArray<KeyEvent>>(16); 

	// std::shared_ptr<I_CyclicArray<I_KeyEvent>> h2 
	// 	= std::static_pointer_cast<I_CyclicArray<I_KeyEvent>>(
	// 		std::make_shared<CyclicArray<KeyEvent>>(16)
	// 	); 
};


}//~namespace _

