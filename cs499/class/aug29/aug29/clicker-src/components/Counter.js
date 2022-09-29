
import './Button.css';

function Counter({useClass,value,onClickFunc})
{
    return(
        <button className={useClass} onClick={onClickFunc}> {value} </button>
    )
}

export default Counter;

