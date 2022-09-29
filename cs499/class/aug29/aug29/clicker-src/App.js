
import React, {useState} from 'react';
import Counter from './components/Counter.js';
import './App.css';

function App()
{
    const [counter, setCounter] = useState(0);

    return(
        <div className='button-container'>
            <Counter useClass="button" value={"Dec\n"+counter.toString(10)} onClickFunc={() => setCounter(counter+1)}/>
            <Counter useClass="button" value={"Hex\n"+counter.toString(16)} onClickFunc={() => setCounter(counter+1)}/>
            <Counter useClass="button" value={"Oct\n"+counter.toString(8)} onClickFunc={() => setCounter(counter+1)}/>
            <Counter useClass="button button-bin" value={"Bin\n"+counter.toString(2)} onClickFunc={() => setCounter(counter+1)}/>
        </div>
    )
}
export default App;
