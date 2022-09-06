import {useState, useEffect} from 'react'

function App()
{
	const [tick, setTick] = useState(0)

	function update()
	{
		setTick((Date.now()/1000).toFixed(0))
	}
	useEffect (() => {
		const ticker = setInterval(update,1000)
		return () => clearInterval(ticker)
	}, [])
	
	return ( <div style> )
}
