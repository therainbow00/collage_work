
import React, {useState} from 'react';

function Counter({value,onClickFunc})
{
    return(
        <button onClick={onClickFunc}> {value} </button>
    )
}
function App()
{
    const [counter, setCounter] = useState(0);

    return(
        <Counter value={counter.toString()} onClickFunc={() => setCounter(counter+1)}/>
    )
}
export default App;
