#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"�p��z�u�@��"NOR);

	set("long", @LONG
�o�O�p��z���u�@�ǡA�A�i�ݨ��P�򳣶K���F�u�`�Ю��l�v��Poster�C
�M�@�i�@�i���g�u�Ӥ��C�V���ݥi�H�ݨ��@��VCD�d�M���d�A�������O
�u�`�Ю��l�v�Һt�L���@���M�g�u�A���y�W�ҡA�е��ڦh�@�I�ɶ��I�z
LONG

	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"green.c",
  "naboo" : __DIR__"area/naboo/middle.c",	
  "enter" : __DIR__"area/inn",
  "star" : __DIR__"starwars",
 "war" : __DIR__"a10.c",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"kelly.c" : 1,
   __DIR__"kyoko.c" : 1,
__DIR__"area/naboo/npc/bar.c" :10,
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);


	setup();
	call_other("/obj/board/mulder_b.c", "???");
}
void init()
{
	call_out("leave_message",3,this_player());
	call_out("entercheck",2,this_player());
}

void entercheck(object ob)
{
 if(userp(ob))
 {
  if(wiz_level(ob) < wiz_level("(immortal)"))
  {
   message_vision(HIR"�`�Ю��l���G"+ob->name()+" �A��|�]�ӳo�A�A�Q�I�r(-_-)�I\n"NOR, ob);
   ob-> die();
  } else {
   message_vision(HIY"\n�`�Ю��l��: �A�n�I�I "+ob->name()+"�j�j�I�����o�򦭧r�I�I\n"NOR, ob);
  }
 }
 return;
}

void leave_message(object me)
{
	object mulder,ob2;
	if( mulder=find_player("mulder"))
	{
		if(me->query("id")!="mulder")
		{
			ob2=present("mulder",this_object());
			if( ob2 ) return;
			add("guest",me->query("id")+" - ");
			tell_object(mulder ,"[1;37m���X�Ȩ��o!("+me->query("name")+")[m\n");
			tell_object(me,"�`�Ю��l(Kyoko)�i�D�A:�A�n�r�I�I�p��z�f���o�I\n");
		}
		else
		{
			if(query("guest"))
			{
				tell_object(me,"[1;37m���Ѫ��X�Ȧ�:"+query("guest")+"[m\n");
				delete("guest");
			}
			else
			{
				tell_object(me,"[1;37m�����٨S���X�ȨӹL[m\n");
			}
		}
	}
	else
	{
		add("guest",me->query("id")+" - ");
		tell_object(me,"[1;37m�`�Ю��l(Kyoko)�i�D�A: Mulder�٨S�W�u�@�A�A�H�N�}�}�a�I[m\n");
	}
 

}