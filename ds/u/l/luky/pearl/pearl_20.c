// Room: /u/l/luky/room/pearl_20.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]�_��"NOR);
set("long", @LONG

�ġġġġ�   �o�̬O�ѹp�����F�_���C�A�ݨ���  �ġġġĢ���
"  .   -   �����ӤT���Ϊ��p�}�A�}�f�٦��@�ǳ�        �y: ��
:      -   ���Y�C�q�o�̩��n�O�ï]�F��A����h       -�y: ��
= ."   -   �O���x���ï]�_��A���̦��X�ɤQ���{       =�y: ��
==-  " -   �N�ƪ��ؿv���C                 -      -=[32m��[m�y: ��
�áááá�                   �ááááááááááááâ���


LONG
);
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_19",
"south" : __DIR__"pearl_21",
]));
set("item_desc",([
"hole":"�@�ӤT���Ϊ��p�}�C\n",
"bone":"�@��Y�Ѫ������Y�C\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}

void init()
{
 add_action("do_search","search");
}

int do_search(string arg)
{
 object me,obj;
 me=this_player();
 if(!arg) return notify_fail("�A�n�j�d����?\n");
 if(arg=="hole" || arg=="�p�}" || arg=="�}")
 {
  if(query_temp("nocork")) return notify_fail("�p�}�̭��S������F��.\n");
  message_vision("$N�q�p�}�����F�@�Ӥp���C\n",me);
  obj=new(__DIR__"obj/cork");
  if ( (obj->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
  {
   write("�A�����ʤp���, ��@�n..�p��뱼��a�W�F!!\n");
   obj->move(environment(me));
  } else
  obj->move(me);
  set_temp("nocork",1);
  call_out("do_reborn",600);
  return 1;
 }
 if(arg=="bone" || arg=="�����Y" || arg=="���Y")
 {
  if(query_temp("bone")>10) return notify_fail("�ѤU�@��ݴ�..�S������n�����F.\n");
  message_vision("$N�q�����Y�����F�@�������b�C\n",me);
  obj=new(__DIR__"npc/item/fisharrow");
  if ( (obj->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
   return notify_fail("�i�O�A���O�q����,�����_��\n");
  obj->move(me);
  add_temp("bone",1);
  call_out("do_reborn",600);
  return 1;
 }
 return 0;
}

void do_reborn()
{
 this_object()->delete_temp("nocork");
 this_object()->delete_temp("bone");
}