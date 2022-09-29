
import { useState, useEffect } from 'react';
import './App.css';

function App()
{
  const [seconds, setSeconds] = useState(0);
  const [isRunning, setIsRunning] = useState(false);

  function toggle() {
    setIsRunning(!isRunning);
  }

  function reset() {
    setIsRunning(false);
    setSeconds(0);
  }

  useEffect(() => {
    if(isRunning) {
      let nextTick = setInterval(() => { setSeconds(seconds + 0.01); }, 10);
      return () => clearInterval(nextTick);
    } else {
      return () => clearInterval();
    }
  }, [isRunning, seconds]);

  return (
    <div className="app">
        <div className="time">
            {seconds.toFixed(2)}
        </div>
        <button className={`button button-${isRunning ? 'active' : 'inactive'}`} onClick={toggle}>
            {isRunning ? 'Stop' : 'Start'}
        </button>
        <button className="button" onClick={reset}>
            Reset
        </button>
    </div>
  );
};

export default App;

