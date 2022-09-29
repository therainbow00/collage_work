
import { useState } from 'react';
import { FaArrowDown, FaArrowUp } from 'react-icons/fa';
import './Accordion.css';

const Accordion = ({ title, content }) => {
  const [isActive, setIsActive] = useState(false);

  return (
    <div className="accordion-item">
      <div className="accordion-title" onClick={() => setIsActive(!isActive)}>
        <div className='subitem'>{title}</div>
        <button className='subitem'> {isActive ? <FaArrowUp /> : <FaArrowDown />} </button>
      </div>
      {isActive && <div className="accordion-content">{content}</div>}
    </div>
  );
};

export default Accordion;
