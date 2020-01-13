open Framework;
open TennisKata.Game;

describe("Test Game transitions", ({test}) => {

  test("Given PlayerOne then PlayerTwo is different", ({expect}) => {
    expect.notEqual(PlayerOne, PlayerTwo)
  });

  test("Given deuce when PlayerOne wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerOne), Advantage(PlayerOne))
  });

  test(
    "Given advantage when advantaged player wins then score is correct",
    ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = advantagedPlayer;
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Game(advantagedPlayer),
    );
  });

  test("Given advantage when the other player wins then score is Deuce",
  ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = other(advantagedPlayer);
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Deuce,
    );
  });

  test(
    "Given player: 40 when wins then score is Game for this player",
    ({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(
      scoreWhenForty(fortyThirty, fortyThirty.player),
      Game(fortyThirty.player),
    );
  });

  test(
    "Given player: 40 | other : 30 when other wins then score is Deuce",
    ({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(
      scoreWhenForty(fortyThirty, other(fortyThirty.player)),
      Deuce
    );
  });

  test("Given player: 40 | other : 0 when other wins then score is fortyFifteen",
  ({expect}) => {
    let fortyLove = {player: PlayerOne, otherPlayerPoint: Love};
    let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
    expect.equal(
      scoreWhenForty(fortyLove, other(fortyLove.player)),
      Forty(fortyFifteen)
    );
  });

  test(
    "Given player: 15 | other : 15 when player wins then score is 30/15",
    ({expect}) => {
    let fifteenFifteen = {playerOne: Fifteen, playerTwo: Fifteen};
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    expect.equal(
      scoreWhenPoints(fifteenFifteen, PlayerOne),
      Points(thirtyFifteen)
    );
  });

  test("Given player: 0 | other : 15 when other wins then score is 0/30",
  ({expect}) => {
    let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
    let loveThirty = {playerOne: Love, playerTwo: Thirty};
    expect.equal(
      scoreWhenPoints(loveFifteen, PlayerTwo),
      Points(loveThirty)
    );
  });

  test("Given player: 30 | other : 15 when player wins then score is 40/15",
    ({expect}) => {
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
    expect.equal(
      scoreWhenPoints(thirtyFifteen, PlayerOne),
      Forty(fortyFifteen)
    );
  });

  /* Tests function string_of_player */
  test("Print Player One",
    ({expect}) => {
      expect.equal(
        string_of_player(PlayerOne),
        "Player One"
      );
  });

  test("Print Player Two",
    ({expect}) => {
      expect.equal(
        string_of_player(PlayerTwo),
        "Player Two"
      );
  });

  /* Tests function string_of_point */
  test("Print Love Point",
    ({expect}) => {
      expect.equal(
        string_of_point(Love),
        "0"
      );
  });

  test("Print Fifteen score",
    ({expect}) => {
      expect.equal(
        string_of_point(Fifteen),
        "15"
      );
  });

  test("Print Thirty score",
    ({expect}) => {
      expect.equal(
        string_of_point(Thirty),
        "30"
      );
  });

  test("Print Forty score",
    ({expect}) => {
      expect.equal(
        string_of_point(Forty),
        "40"
      );
  });

  /* Tests function string_of_score */
  test("Score Fifteen/Thirty",
    ({expect}) => {
      let fifteenThirty = {playerOne: Fifteen, playerTwo: Thirty};
      expect.equal(
        string_of_score(Points(fifteenThirty)),
        "15/30"
      );
  });

  test("Score Love/Fifteen",
    ({expect}) => {
      let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
      expect.equal(
        string_of_score(Points(loveFifteen)),
        "0/15"
      );
  });

  test("Score Deuce",
    ({expect}) => {
      expect.equal(
        string_of_score(Deuce),
        "40/40 : Deuce"
      );
  });

  test("Advantage for Player One",
    ({expect}) => {
      expect.equal(
        string_of_score(Advantage(PlayerOne)),
        "Advantage for Player One"
      );
  });

  test("Advantage for Player Two",
    ({expect}) => {
      expect.equal(
        string_of_score(Advantage(PlayerTwo)),
        "Advantage for Player Two"
      );
  });

  test("The winner is Player One",
    ({expect}) => {
      expect.equal(
        string_of_score(Game(PlayerOne)),
        "Winner is Player One"
      );
  });
  
  test("The winner is Player Two",
    ({expect}) => {
      expect.equal(
        string_of_score(Game(PlayerTwo)),
        "Winner is Player Two"
      );
  });

  test("Score 40/0",
    ({expect}) => {
      let forty = {player: PlayerOne, otherPlayerPoint: Love};
      expect.equal(
        string_of_score(Forty(forty)),
        "Player One : 40/0 : Player Two"
      );
  });

  test(
    "Score 15/40",
    ({expect}) => {
      let forty = {player: PlayerTwo, otherPlayerPoint: Fifteen};
      expect.equal(
        string_of_score(Forty(forty)),
        "Player One : 15/40 : Player Two"
      );
  });

});