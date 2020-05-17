new Vue({
  el: '#app',
  data: {
    gameOver: true,
    playerWon: undefined,
    player: {    
      health: 100,
      hits: []
    },
    monster: {      
      health: 100,
      hits: []
    },
  },
  computed: {
    cockpitMessage: function() {
      if (this.playerWon) {
        return 'You won! Play again.';
      } else if (this.playerWon === false) {
        return 'You lost! Play again.';
      } else {
        return 'Play';
      }
    }
  },
  methods: {
    attack: function(playerAttackWeight, monsterAttackWeight) {
      const monsterDamage = this.getRandomInt({max: monsterAttackWeight});
      const playerDamage = this.getRandomInt({max: playerAttackWeight});            

      if (this.monster.health - playerDamage <= 0) {
        this.monster.health = 0;
        this.gameOver = true;
        this.playerWon = true;    
      } else {
        this.monster.health -= playerDamage;
      }

      if (this.player.health - monsterDamage <= 0) {
        this.player.health = 0;
        this.gameOver = true;
        this.playerWon = false;
      } else {
        this.player.health -= monsterDamage;
      }

      this.monster.hits.push(playerDamage);
      this.player.hits.push(monsterDamage);
    },
    heal: function(event, weight = 20) {
      const health = this.getRandomInt({max: weight});
      this.player.health = this.player.health + health > 100 ? 100 : this.player.health + health;
    },
    getRandomInt: function({min = 1, max = 100} = {min: 5, max: 100}) {      
      return Math.floor((Math.random() * max) + min);      
    },
    initGame: function() {
      this.gameOver = false;
      this.playerWon = undefined;      
      this.player.health = 100;
      this.monster.health = 100;
      this.player.hits = []
      this.monster.hits = []
    }    
  }
});