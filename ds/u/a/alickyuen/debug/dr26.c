// Room: /u/a/alickyuen/area/dr26.c
// learn literate
// New room
// For join doctor use
inherit ROOM;
void create()
{
	set("short", "ST�CHospital�IComputer-room");
	set("long", @LONG
�o�̬O�o����|���q���оǫǡA�β{�ɦb���i����ިӱоǡA�@�Ʊ�
�Ȥl��b�o�̡A�٦��o���h�X���O���A�u���ܮe���O�H�εۡC�O�A����Y
���O�A���b�Ȥl�W���H�������H�H�A�����b�ǲߡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr25",
]));
set("light",1);
set("no_recall",1);
set("no_fight",1);
set("no_kill",1);
set("no_exert",1);
set("no_cast",1);
	set("world", "future");
	set("no_clean_up", 0);
	setup();
}

int room_effect()
{
object me;
me=this_player();
          switch(random(10))
        {
         case 0:
                message_vision("�A����ı�o�I�e�A�}�l�ΤF�_�ӡC\n",me);
break;
         case 1:
                message_vision("�A�Pı�츣�������]�X�@�j��A�H�e�S�Ǫ��r�C\n",me);
break;         
case 2:
                message_vision("�A��M����L�ӡA�n������]�S�o�͹L�A���A�������ϩ��R���ǰݡC\n",me);
break;
         default:
message_vision("�A��������M�X�{�@�ǩ_�����v���A�A����Q���@�B�B�a�i�J�o�����@�ɤ����D�D�D\n",me);
break;       
}
if (me->query_skill("literate",1) <100)
                {
                        me->improve_skill("literate",me->query_int()/10+random(2));
                }
}
