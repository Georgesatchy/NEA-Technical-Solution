import pyglet
import cipherTools
import pyperclip

from pyglet.window import key, mouse
import pyglet.shapes as shapes

class MainWindow(pyglet.window.Window):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.background = pyglet.sprite.Sprite(pyglet.image.load('background.jpg'))
        self.image = pyglet.resource.image('kitten.jpg') # Example image 
        # self.event_logger = pyglet.window.event.WindowEventLogger()
        # self.push_handlers(self.event_logger)
        self.title = pyglet.text.Label('Cipher Tools (Type to input text)',
            font_name='Comic Sans',
            font_size=20,
            x=self.width//2, y=self.height-20,
            anchor_x='center', anchor_y='center'
        )
        self.text = ""
        self.document = pyglet.text.document.FormattedDocument("")
        self.document.set_style(0, len(self.document.text), dict(font_name='Comic Sans', font_size=16, color=(255, 255, 255, 255)))
        self.text_layout = pyglet.text.layout.TextLayout(self.document, self.width, self.height//2, multiline=True)
        self.text_layout.x = self.width//2
        self.text_layout.y = self.height - 50
        self.text_layout.anchor_x = "left"
        self.text_layout.anchor_y = "top"
        self.paste_button = shapes.Rectangle(x=self.width-100, y=self.height-40, width=100, height=40, color=(55, 55, 255))
        self.paste_button_text = pyglet.text.Label(
            'Paste',
            font_name='Comic Sans',
            font_size=20,
            x=self.width-50, y=self.height-20,
            anchor_x='center', anchor_y='center'
        )
        self.solve_button = shapes.Rectangle(x=self.height//4-100, y=self.height//4*3-40, width=200, height=80, color=(55, 55, 255))
        self.solve_button_text = pyglet.text.Label(
            'Autosolve',
            font_name='Comic Sans',
            font_size=20,
            x=self.height//4, y=self.height//4*3,
            anchor_x='center', anchor_y='center'
        )
        self.alive = 1

    def format_document(self):
        self.document.text = "\n".join([self.text[i: i+16] for i in range(0, len(self.text), 16)])
        self.document.set_style(0, len(self.document.text), dict(font_name='Comic Sans', font_size=16, color=(255, 255, 255, 255)))

    def on_draw(self): # Runs whenever Pyglet is ready to redraw its content.
        self.clear()
        self.background.draw()
        self.image.blit(0, 0)
        self.title.draw()
        self.paste_button.draw()
        self.paste_button_text.draw()
        self.solve_button.draw()
        self.solve_button_text.draw()
        self.text_layout.draw()
        self.flip()

    def on_key_press(self, symbol, modifiers): # Runs when a key is pressed, useful for collision detection
        if symbol == key.ENTER: # Run auto-decrypt?
            print('Enter key was pressed')

    def on_mouse_press(self, x, y, button, modifiers):
        if button == mouse.LEFT: # Collision detection for buttons here!
            if (x > self.width-100) and (y > self.height-40):
                self.text = pyperclip.paste()
                self.format_document()
            elif (self.height//4-100 < x < self.height//4+100) and (self.height//4*3-40 < y < self.height//4*3+40):
                self.text = "Solution: " + cipherTools.caesar(self.text)
                self.format_document()

    def on_text(self, text):
        self.text += text
        self.format_document()

    def on_text_motion(self, motion):
        if motion == 65288: ## 65288 represents the backspace motion
            self.text = self.text[:-1]
            self.format_document()

    def on_close(self):
        self.alive = 0
        self.close()

    def run(self):
        while self.alive:
            self.on_draw()
            event = self.dispatch_events()

window = MainWindow()
window.run()

pyglet.app.run()