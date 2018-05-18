"use strict";

const five = require("johnny-five");
const board = five.Board();

(async () => {
  // Wait for the board to load before doing anything
  await new Promise((resolve, reject) => { board.on("ready", resolve); });
})();
