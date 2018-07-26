import { Scene } from 'phaser'


export default class PlayScene extends Scene {
  constructor () {
    super({ key: 'PlayScene' })
  }

  create () {
    this.add.image(400, 300, 'sky')

    const player = this.physics.add.sprite(400, 200, 'bomb')
    player.setCollideWorldBounds(true)

    const food = this.physics.add.sprite(400, 400, 'food')
    food.setCollideWorldBounds(true)

    //console.log(eos)
    console.log(Phaser)

    this.input.keyboard.on('keydown_UP', function (event) {
      console.log('Hello from the UP Key!');
      player.y -= 4;  
    });

    this.input.keyboard.on('keydown_DOWN', function (event) {
      console.log('Hello from the DOWN Key!');
      player.y += 4;
    });

    this.input.keyboard.on('keydown_LEFT', function (event) {
      console.log('Hello from the LEFT Key!');
      player.x -= 4;
    });

    this.input.keyboard.on('keydown_RIGHT', function (event) {
      console.log('Hello from the RIGHT Key!');
      player.x += 4;
    });
    
    //bomb.setBounce(1)
    //bomb.setVelocity(200, 20)
  }

  update () {
  }
}
