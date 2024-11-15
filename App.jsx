import React, { Component } from "react";

// Ini Functional Component Button
function ButtonFunctional({ variant }) {
  return (
    <button
      className={`h-10 px-6 font-semibold rounded-md ${variant} text-white hover:bg-yellow-400 transition-300`}
      type="button"
    >
      Functional Button
    </button>
  );
}

// Ini Class Component Button
class ButtonClass extends Component {
  render() {
    const { variant } = this.props;
    return (
      <button
        className={`h-10 px-6 font-semibold rounded-md ${variant} text-white hover:bg-yellow-400 transition-300`}
        type="button"
      >
        Class Button
      </button>
    );
  }
}

export default function App() {
  return (
    <div className="text-2xl flex justify-center bg-gray-200 min-h-screen items-center">
      <div className="flex gap-4">
        {/* Button Dengan Children */}
        <button className="h-10 px-6 font-semibold rounded-md bg-blue-500 text-white hover:bg-yellow-400 transition-300">
          Button Dengan Children
        </button>

        {/* Button Dengan Props */}
        <button
          className="h-10 px-6 font-semibold rounded-md bg-green-500 text-white hover:bg-yellow-400 transition-300"
          type="button"
        >
          Button Dengan Props
        </button>

        {/* Button Menggunakan Functional Component */}
        <ButtonFunctional variant="bg-red-500" />

        {/* Button Menggunakan Class Component */}
        <ButtonClass variant="bg-pink-400" />
      </div>
    </div>
  );
}
