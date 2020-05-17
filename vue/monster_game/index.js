new Vue({
  el: '#app',
  data: {
    isGameOver: true,
    playerWon: false,
    player: {
      name: "Foo",
      health: 100,
      hits: []
    },
    monster: {
      name: "Monster",
      health: 100,
      hits: []
    },
  },
  methods: {
    attack: function(event, weight = 20) {
      const monsterDamage = this.getRandomInt({max: weight});
      const playerDamage = this.getRandomInt({max: weight});            

      if (this.monster.health - playerDamage <= 0) {
        this.monster.health = 0;
        this.playerWon = true;
        this.isGameOver = true;
      } else {
        this.monster.health -= playerDamage;
      }

      if (this.player.health - monsterDamage <= 0) {
        this.player.health = 0;
        this.playerWon = false;
        this.isGameOver = true;
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
    getWinner: function() {
      return player.health < 0 ? 'Monster' : 'You';
    },
    getRandomInt: function({min = 1, max = 100} = {min: 5, max: 100}) {      
      return Math.floor((Math.random() * max) + min);      
    }
  }
});