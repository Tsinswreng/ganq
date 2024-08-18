import { mouse } from '@backend/impl/Mouse';
import { Direct2d } from '@shared/enum/Direct2d';
let i = 0
setInterval(()=>{
	if(i % 2 === 0){
		mouse.Move(Direct2d.up, 10)
	}
	else{
		mouse.Move(Direct2d.down, 10)
	}
	i++
}, 1000)

