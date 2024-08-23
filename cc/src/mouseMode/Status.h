#include "common.h"
#include "impl/KeyEvent.h"
#include "tools/CyclicArray/CyclicArray.h"
#include "tools/CyclicArray/I_CyclicArray.h"
#include "IF/I_KeyEvent.h"
#include "./KeyOpt.h"
#include <memory>
// #include <memory>
// #include <vector>
namespace _ {

namespace {
// I_CyclicArray是CyclicArray的父類、I_KeyEvent是KeyEvent的父類、an是共享指針
	using I_KeyHistory = I_CyclicArray<an<I_KeyEvent>>;
	//using KeyHistory = CyclicArray<an<KeyEvent>>;
	using KeyHistory = CyclicArray<an<I_KeyEvent>>;
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

	i32 mouseStep_normal_(){return _mouseStep_normal;}
	void mouseStep_normal_(i32 v){_mouseStep_normal = v;}

	i32 mouseStep_fast_(){return _mouseStep_fast;}
	void mouseStep_fast_(i32 v){_mouseStep_fast = v;}

	/** 當前KeyEvent是否同於上個 */
	bool duplicateEvent_(){return _duplicateEvent;}
	void duplicateEvent_(bool v){_duplicateEvent = v;}

	i64 cnt = 0;



	void test(){
		//std::make_shared<CyclicArray<an<KeyEvent>>>(16);
		// std::make_shared<std::vector<
		// 	std::shared_ptr<KeyEvent>
		// >>(10);

		// KeyHistory* kh = new KeyHistory(16);
		// I_KeyHistory* ih;
		// ih = static_cast<I_KeyHistory*>(kh);
//Incompatible pointer types assigning to 'I_KeyHistory *' (aka 'I_CyclicArray<shared_ptr<_::I_KeyEvent>> *') from 'KeyHistory *' (aka 'CyclicArray<shared_ptr<_::KeyEvent>> *')clang(typecheck_convert_incompatible_pointer)
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
	i32 _mouseStep_normal = 50;

	i32 _mouseStep_fast = 200;

	bool _duplicateEvent = false;



//No viable conversion from 'shared_ptr<CyclicArray<_::KeyEvent>>' to 'shared_ptr<I_CyclicArray<I_KeyEvent>>'clang(typecheck_nonviable_condition)
	// std::shared_ptr<I_CyclicArray<I_KeyEvent>> h 
	// 	= std::make_shared<CyclicArray<KeyEvent>>(16); 

	// std::shared_ptr<I_CyclicArray<I_KeyEvent>> h2 
	// 	= std::static_pointer_cast<I_CyclicArray<I_KeyEvent>>(
	// 		std::make_shared<CyclicArray<KeyEvent>>(16)
	// 	); 
};


}//~namespace _

