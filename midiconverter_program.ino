#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);

void HandleNoteOn(byte channel, byte pitch, byte velocity) {
  MIDI.sendNoteOn(pitch-12, velocity, channel);
}

void HandleNoteOff(byte channel, byte pitch, byte velocity) {
   MIDI.sendNoteOff(pitch-12, velocity, channel);
}

void setup()
{
  MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages
  MIDI.turnThruOff();

  // Connect MIDI status changes involving a channel to handlers
  MIDI.setHandleNoteOn(HandleNoteOn);
  MIDI.setHandleNoteOff(HandleNoteOff);
}

void loop()
{
  MIDI.read();
}
 
