import { useSelector, useDispatch } from "react-redux";
import { increment, decrement } from "./store";

function App() {

  const count = useSelector(state => state.counter.count);

  const dispatch = useDispatch();

  return (
    <>
      <h1>Count: {count}</h1>

      <button onClick={() => dispatch(increment())}>
        Increment
      </button>

      <button onClick={() => dispatch(decrement())}>
        Decrement
      </button>
    </>
  );
}

export default App;