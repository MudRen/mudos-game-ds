// Cominging JOhnny's Board
// (TRASH EDITON) in DS
#include <ansi2.h>

inherit BULLETIN_BOARD;
void new_message();

void create()
{
        set_name("[ Omega Board ] ", ({ "board" }) );
        set("location", "/u/c/cominging/workroom.c");
        set("board_id", "coming_b");
        set("long", "怪異的留言版，有著提醒主人留言的功\能。\n" );
        setup();
        set("capacity", 120);
        set("master",({ "cominging" }));
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
  write(BEEP"\n\n"HIW"   "BBLU+BLINK"┌─"NOR+ESC"[47m"+BLK" Cominging Board 系統 "BBLU+BLINK+HIW"─┐\n"NOR
        HIW"   "BBLU+BLINK"│                          "BLINK+HIW"│\n"NOR
        HIW"   "BBLU+BLINK"│   　"NOR+BBLU+HIY"您 有 新 留 言 。    "BLINK+HIW"│\n"NOR
        HIW"   "BBLU+BLINK"│                          "BLINK+HIW"│\n"NOR
        HIW"   "BBLU+BLINK"└─────────────┘\n\n"NOR);
}
