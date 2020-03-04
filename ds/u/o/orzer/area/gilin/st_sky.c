#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "���ŤW");
  set ("long", @LONG

�A�ǵ۱j�j���\�񭸳��ɤW�F���šA�o�̵�������A�w�g�i�H�M���ݨ�
�Ŧa�A�A�]�o�{�쥨�j�j�����A���G���O�ܻ��A�ݨӤ]�\�i�H�ոլݩ��䤤
�@�Ӥ�V���D�L�h�ݬݡC

LONG
);
  set("no_recall",1);
  set("no_goto",1);
  set("no_horse_member",1);  set("item_desc", ([
        "�Ŧa" : "�j��L�����@�ӪŦa�A�ݨӻᬰ��a�A�����a�Z�����O�ܻ��A�i�H���խ����L�h�ݬ�?(fall_to)�C\n",            
        "���j�j��" : "�@�ʥ��j���j��A�Pı�N�O�j�줤�����A�ݨӴN�b���ǡA�i�H���խ����L�h�H(fall_to)\n",            
         ]));   
  setup();
}
  

void init()
{
  object me;
  me = this_player(); 
  remove_call_out("fall_down");
  call_out("fall_down",20,me);   
  call_out("write_note",1);
}

void write_note()
{ 
  write(HIC"�A�Ө�F���Ť��A�u���g�����j���A�٬O�_�S�A�A�i�H�Ҽ{���թ���L��V����(fall_to)�C\n"NOR);
  add_action("do_fall","fall_to");
}


void fall_down(object ppl)
{
  if(!ppl || environment(ppl) != this_object() ) return;
  write(HIM"�A���M�@�f�𴣤��W�ӡA�I�l�@�}���B�A����@�I���F�U�h\n"NOR);
  ppl->move(__DIR__"t18");
  ppl->start_busy(2);
  tell_room(environment(ppl), "�ѪŤ@�Ӷ¼v�V�ܶV�j�A�P��@�}����«�ʡA"+ppl->name()+"�q�Ť����F�U�ӡI\n", ({ ppl }));
}


int do_fall(string arg)
{
  object me;
  me = this_player();
  if(!arg && (arg!="�Ŧa" || arg !="���j�j��") ) return notify_fail("�S���o�Ӧa��i�H������\n");
  write("�A����L�L�e�ɡA�}�W���իe���A�K�N�⭰������V���ܡA�u���a���V�ӶV��\n");   
  if(arg=="�Ŧa")
  {
   me->move(__DIR__"stn8"); 
   me->start_busy(1);
   write(HIG"�u���A����w�w�s���A�|�g�@�}���⨫�ۡA�i�O�U�����O�D�o���Q�Ʊ��F�A�A���w��F�F�Ŧa\n"NOR);   tell_room(environment(me), "�ѪŤ@�Ӷ¼v�V�ܶV�j�A�P��@�}����«�ʡA"+me->name()+"�q�Ť����F�U�ӡI\n", ({ me }));
  }
  if(arg=="���j�j��")
 {
   me->move(__DIR__"stn9");
   me->start_busy(1);
   write(HIG"�u���A����w�w�s���A�P��K���̰ʡA�i�O�U�����O�D�o���Q�Ʊ��F�A�A���w��F�F���j�j��\n"NOR);
   tell_room(environment(me), "�ѪŤ@�Ӷ¼v�V�ܶV�j�A�P��@�}�K���̰ʡA"+me->name()+"�q�Ť����F�U�ӡI\n", 
   ({ me }));
}
  return 1;
}

