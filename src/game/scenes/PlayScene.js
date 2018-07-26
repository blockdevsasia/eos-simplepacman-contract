import { Scene } from 'phaser'


export default class PlayScene extends Scene {
  constructor () {
    super({ key: 'PlayScene' })
  }

  create () {
    this.add.image(400, 300, 'sky')

    const player = this.physics.add.sprite(400, 200, 'bomb')
    player.setCollideWorldBounds(true)

    //console.log(eos)
    console.log(Phaser)

    this.input.keyboard.on('keydown_UP', function (event) {
      console.log('Hello from the UP Key!');
      player.y -= 4;  
    });

    this.input.keyboard.on('keydown_DOWN', function (event) {
      console.log('Hello from the UP Key!');
      player.y += 4;
    });

    this.input.keyboard.on('keydown_LEFT', function (event) {
      console.log('Hello from the UP Key!');
      player.x -= 4;
    });

    this.input.keyboard.on('keydown_RIGHT', function (event) {
      console.log('Hello from the UP Key!');
      player.x += 4;
    });

    /*var keys = {
      up = this.input.keyboard.addKey(Phaser.Input.Keyboard.KeyCodes.UP),
      down = this.input.keyboard.addKey(Phaser.Input.Keyboard.KeyCodes.DOWN),
      left = this.input.keyboard.addKey(Phaser.Input.Keyboard.KeyCodes.LEFT),
      right = this.input.keyboard.addKey(Phaser.Input.Keyboard.KeyCodes.RIGHT)
    }*/
    
    //bomb.setBounce(1)
    //bomb.setVelocity(200, 20)
  }

  update () {
    //console.log(this)

    /*if (typeof player !== "undefined"){
      if (keys.left.isDown)
      {
          player.x -= 4;
      }
      else if (keys.right.isDown)
      {
          player.x += 4;
      }

      if (keys.up.isDown)
      {
          player.y -= 4;
      }
      else if (keys.down.isDown)
      {
          player.y += 4;
      }*/

      /*if (this.input.keyboard.isDown(Phaser.Keyboard.LEFT))
      {
          player.x -= 4;
      }
      else if (this.input.keyboard.isDown(Phaser.Keyboard.RIGHT))
      {
          player.x += 4;
      }

      if (this.input.keyboard.isDown(Phaser.Keyboard.UP))
      {
          player.y -= 4;
      }
      else if (this.input.keyboard.isDown(Phaser.Keyboard.DOWN))
      {
          player.y += 4;
      }

      
    }*/

    
  }
}
