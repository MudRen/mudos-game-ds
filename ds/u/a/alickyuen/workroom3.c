#include <ansi.h>
inherit ROOM;
// string look_list(object me);
int do_say(string arg);
void create()
{
	set("short", MAG"�ѤU�Ĥ@�a���u�@��"NOR);
set("long",
BLK"�A���b�K�@�ͪ��@���u�@�Ǹ̡A���e��ۨⰦ�ܢޢѡA�@���s�s���k
�l�A�t�@���O�L���O�ߡC�t�~�A�٬ݨ��a�W���@�ӫH�c�M�@�Ӥp�аO�A�W
��n���g�F�@�Ǧr�C\n"NOR
);
	set("item_desc", ([ /* sizeof() == 1 */
  "�p�аO" : "�V�O�gCLASS���I\n",
"�H�c" : "�@�ӫH�c�A�A�i�H�����Y���S���H�C\n",
// "rich_list": (: look_list :),
]));
	set("world", "future");
	set("light", 1);
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 8 */
  "enter" : __DIR__"workroom2.c",
  "east" : "/d/wiz/hall1",
"mj" : "/open/world1/tmr/area/mjroom", 
"area" : __DIR__"down_city/map_11_8",
  "ticket" : "/open/world2/shengsan/aovandis/room001",
"guild":"/d/wiz/hall_guild",
"future":"/open/world3/alickyuen/area/inn.c",
]));
  set("objects",([
//  __DIR__"npc/1":1,
 __DIR__"npc/sguard2":1,
 ]));
        set("no_kill",1);
        set("no_exert",1);
        set("no_fight",1);
        set("no_cast",1);
        set("no_recall",1);
 //       set("no_goto",1);
    set("no_shoot",1);
// set("no_home",1);
	set("no_clean_up", 0);
	setup();
 call_other("/obj/board/alickyuen_b", "???");
	}
void init()
{
        call_out("leave_message",3,this_player());
        call_out("entercheck",2,this_player());
add_action("do_say","say");
add_action("do_kickgo","kickgo");
add_action("do_search","search");
}

void entercheck(object ob)
{
 if(userp(ob))
 {
  if(wiz_level(ob) < wiz_level("(immortal)"))  
  {
   message_vision(HIR"�s���k�l���G"+ob->name()+" �A�]�ӳo�̡A�A�S�Q���i�f�i�֤j�H�r�I�S\n"NOR, ob);
   ob-> move ("/d/wiz/hall1");
  } else {
   message_vision(HIY"\n�i�f�i��-�O�߻��D:  "+ob->name()+",�o�򦭨ӱ����i�f�i�֤j�H�r....-_-\n"NOR, ob);
  }
 }
 return;
}

void leave_message(object me)
{
        object alickyuen,ob2;
        if( alickyuen=find_player("alickyuen"))
        {
                if(me->query("id")!="alickyuen")
                {
                        ob2=present("alickyuen",this_object());
                        if( ob2 ) return;
                        add("guest",me->query("id")+" - ");
                        tell_object(alickyuen ,"���X�Ȩ��o!("+me->query("name")+")\n");
                        tell_object(me,"�s���k�l�i�D�A:�i�f�i�ִ_���F�I�S\n");
                }
                else
                {
                        if(query("guest"))
  {
                                tell_object(me,"���Ѫ��X�Ȧ�:"+query("guest")+"\n");
                                delete("guest");
                        }
                        else
                        {
                                tell_object(me,"�����٨S���X�ȨӹL\n");
                        }
                }
        }
        else
        {
                add("guest",me->query("id")+" - ");
                tell_object(me,"�i�f�i��-�O�߻��D: �i�f�i�֤j�H���F�A���L�����a�I\n");
        }
 

}
int do_say(string arg)
{
	if(!arg) return 0;
	remove_call_out("rush");
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg = replace_string(arg, "$BEEP$", BEEP);
	message_vision(HIY+"$N��:"+arg+"\n"NOR,this_player());
	//write( YEL"�A���R" + arg + "\n"NOR );
//	message("sound", YEL + name + "���R" +  arg + "\n"NOR ,
//		environment(me), me); 
         call_out("rush",300);
        return 1;
}
int do_kickgo(string arg)
{
	object me,who;
	string chief;
	me=this_player();
	//if(!stringp(chief=this_object()->find_living("alickyuen")) ) return notify_fail("�ثe�èS���}�|!\n");
	//if( me->query("id")!=chief ) return notify_fail("�ثe�u���K�@��("+chief+")�~���H!\n");
	if(!arg) return notify_fail("�A�n��֥X�h!?\n");
	who = present(arg, this_object());
	if(!who) return notify_fail("�o�̨S���o�ӤH�C\n");
	if( who == me ) return notify_fail("�A����N�ۤv��X�u�@�ǡC\n");
	message_vision(HIW"$N�N$n��X�u�@�ǡC\n"NOR,me,who);
	add("kickgo",({ who->query("id") }));
	who->move("/d/wiz/hall1");
	return 1;
}
/*
string look_list(object me)
{
        return RECORD_D->query_future_money_rec();
}
*/

int do_search(string arg)
{
        object me,to;
        me = this_player();
        to = new("/open/always/newspaper.c");
        if( !arg ) return 0;
        if( arg!="�H�c" ) return 0;
if( query_temp("getpap") )
{
    return 0;
}
        message_vision("$N�q�H�c�����X�@���ڤۤ���C\n",me);
        to->move(me);
        set_temp("getpap",1);
        call_out("delay",180,this_object());
        return 1;
}

void delay(object room)
{
      delete_temp("getpap");
        return;
}
