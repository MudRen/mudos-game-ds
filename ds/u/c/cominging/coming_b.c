// Cominging JOhnny's Board
// (TRASH EDITON) in DS
#include <ansi2.h>
inherit __DIR__"file_board.c";
void new_message();

void create()
{
        set_name("[ Omega Board ] ", ({ "board" }) );
        set("long", "�ǲ����d�����A���۴����D�H�d�����\\��C\n" );
	set("board_id", "coming_b");
        setup();
}

void init()
{
  mapping *notes;
  notes = query("notes");
  if( getuid(this_player()) == "cominging"
  && pointerp(notes)
  && sizeof(notes)
  && this_player()->query("board_last_read/"+query("board_id")) < notes[sizeof(notes)-1]["time"] )
    call_out("new_message", 0);
  ::init();
}

void new_message()
{
  write(BEEP"\n\n"HIW"   "BBLU+BLINK"�z�w"NOR+ESC"[47m"+BLK" Cominging Board �t�� "BBLU+BLINK+HIW"�w�{\n"NOR
        HIW"   "BBLU+BLINK"�x                          "BLINK+HIW"�x\n"NOR
        HIW"   "BBLU+BLINK"�x   �@"NOR+BBLU+HIY"�z �� �s �d �� �C    "BLINK+HIW"�x\n"NOR
        HIW"   "BBLU+BLINK"�x                          "BLINK+HIW"�x\n"NOR
        HIW"   "BBLU+BLINK"�|�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n\n"NOR);
}
