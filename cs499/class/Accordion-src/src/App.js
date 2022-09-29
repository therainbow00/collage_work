
import Accordion from './Accordion.js';
import { data } from './content.js';

const App = () => {

  return (
    <div>
      <h1>Common Mammals</h1>
      <div className="accordion">
         {data.map(({title,content}) => (
            <Accordion title={title} content={content} />))}
      </div>
    </div>
  );
};

export default App;
