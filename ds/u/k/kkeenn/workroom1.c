#include <room.h>;
#include <ansi.h>;
inherit ROOM;
void create()
{
 set("short",HIC"�s�H�줽�B"NOR);
 set("long","�[�ݥثe���iCmd : help report\n");
set("exits", ([
"east":__DIR__"workroom3.c",
"west":__DIR__"workroom2.c",
 ]) );
set("objects",([
] ) );
set("light",1);
set("no_goto",1);
setup();
}
void init()
{
 add_action("do_help","help");
        if( userp(this_player()) )
                call_out("delay", 0, this_player());
}
int do_help(string arg)
{
 if(arg=="report")
 {
   if( file_size(__DIR__"origami/help.txt")>0 )
   {
    this_player()->start_more( read_file(__DIR__"origami/help.txt") );
    write("\n");
   } else write(" SORRY. �S���o���ɮ�. \n");
  return 1;
 }
 return 0;
}
void delay(object me)
{
        write("
  "HIW"\n\t��e�u�@�G\n"HIM"\t\t�Ƨ�\t�ɪ�\t���O\t�W��\t\t������"+
     "\n\t\t"HIC"����\t����\t�u�|\t�P�ȾԤh\t10%"+
     "\n\t\t����\t����\t�ϰ�\t���F��\t\t0%"+
     "\n\t\t�Ƶ�\t�j�N\t���@\t������\t\t�L%\n\n"
NOR);
}
