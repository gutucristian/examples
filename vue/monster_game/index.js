new Vue({
  el: '#app',
  data: {
    isGameOver: false,
    playerWon: false,
    player: {
      name: "Foo",
      health: 100
    },
    monster: {
      name: "Monster",
      health: 100
    }
  },
  methods: {
    attack: function(event, weight = 20) {            
      const damage = Math.floor((Math.random() * weight) + 1); 
      this.monster.health -= damage;
    },
    heal: function(event, weight = 20) {
      const health = (Math.random() * weight) + 1
      this.player.health += health;      
    },
    getWinner: function() {
      return player.health < 0 ? 'Monster' : 'You';
    }
  }
});