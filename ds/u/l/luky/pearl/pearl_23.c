// Room: /u/l/luky/room/pearl_23.c
#include <ansi.h>
inherit ROOM;
void init();
void create()
{
set("short", HIY"�׹D�|�j��"NOR);
set("long", @LONG

����                                                   ����
���y��    �o�̪��ٳƤQ�����Y�A���G������M���Y�N�o   ��: ��
���y :�j�͡A�|�g�����֥���������C���䪺�K��(Gate) �y: : ��
���y :�j�W���T���ܲ`�����L�A�a�W�ٴ����ۥ��j����� �y: : ��
���y��  �A�o�@�����M�A�Q�������Y�¿p���а󤣦P�C     ��: ��
����                                                   ����


LONG
);
set("objects",([
__DIR__"npc/chuguard":2,
]));
set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"pearl_22",
/*  "west" : __DIR__"pearl_25", */
"south" : __DIR__"pearl_24",
]));
set("item_desc",([
"gate":"\n
�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w
�i�i�i�i�i�i�i�i�i�i�x�i�i�i�i�i�i�i�i�i�i    �W���٦��X�ӫ��s�C
                ���i�x�i��                     �z�w�s�w�s�w�{
                  �i�x�i      ����             �x���x���x���x
                  �i�x�i      ������           �u�w�q�w�q�w�t �ϥΤ�k:
              ��  �i�x�i  ��    ����           �x���x���x���x 
              ��  �i�x�i  ��                   �u�w�q�w�q�w�t press [�Ʀr]
                  �i�x�i                       �x���x���x���x
                  �i�x�i                       �u�w�q�w�q�w�t
                ���i�x�i��                     �x���x���x���x
�i�i�i�i�i�i�i�i�i�i�x�i�i�i�i�i�i�i�i�i�i     �|�w�r�w�r�w�}
�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w
\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
void init()
{
 add_action("do_press","press");
}

int do_press(string arg)
{
 object me;
 me = this_player();
if(!me->query_temp("pass_num")) return notify_fail("�A�����D�K�X�N���0�]�S��\n");
 if(!arg) return notify_fail("    press [�Ʀr]\n");
 else{
  if(me->query_temp("pass_num")==atoi(arg))
  {
   message_vision("\n$N���U�F���s..\n",me);
   me->start_busy(2);
   tell_room(this_object(),"\n
[2J�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w
�i�i�i�i�i�i�i�i�i�i�x�i�i�i�i�i�i�i�i�i�i
                ���i�x�i��                
                  �i�x�i      ����        
                  �i�x�i      ������      
              ��  �i�x�i  ��    ����      
              ��  �i�x�i  ��              
                  �i�x�i                  
                  �i�x�i                  
                ���i�x�i��                
�i�i�i�i�i�i�i�i�i�i�x�i�i�i�i�i�i�i�i�i�i
�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w
");
  call_out("open1",2,this_object());
  call_out("open2",3,this_object());
  call_out("closedoor",30,this_object());
  } else return notify_fail("\n  �A���U���s�A���O�o�S�������C\n");
 }
 return 1;
}
int open1(object me)
{
if(!me) return 0;
 tell_room(me,"\n
[2J�w�w�w�w�w�w�w�w�w�{  �z�w�w�w�w�w�w�w�w�w
�i�i�i�i�i�i�i�i�i�x  �x�i�i�i�i�i�i�i�i�i
              ���i�x  �x�i��              
                �i�x  �x�i      ����      
                �i�x  �x�i      ������    
            ��  �i�x  �x�i  ��    ����    
            ��  �i�x  �x�i  ��            
                �i�x  �x�i                
                �i�x  �x�i                
              ���i�x  �x�i��              
�i�i�i�i�i�i�i�i�i�x  �x�i�i�i�i�i�i�i�i�i
�w�w�w�w�w�w�w�w�w�}  �|�w�w�w�w�w�w�w�w�w

");
}
int open2(object me)
{
if(!me) return 0;
 tell_room(me,"\n
[2J�w�w�w�w�w�w�{              �z�w�w�w�w�w�w
�i�i�i�i�i�i�x              �x�i�i�i�i�i�i
        ���i�x              �x�i��        
          �i�x              �x�i      ����
          �i�x              �x�i      ����
      ��  �i�x              �x�i  ��    ��
      ��  �i�x              �x�i  ��      
          �i�x              �x�i          
          �i�x              �x�i          
        ���i�x              �x�i��        
�i�i�i�i�i�i�x              �x�i�i�i�i�i�i
�w�w�w�w�w�w�}              �|�w�w�w�w�w�w
");
tell_room(me,"\n  ��!!.. �K����M���}�F! \n");
set("exits",([
 "north" : __DIR__"pearl_22",
 "south" : __DIR__"pearl_24",
 "enter":__DIR__"pearl_25",
]));
set("item_desc",([
"gate":"\n
�w�w�w�w�w�w�{              �z�w�w�w�w�w�w
�i�i�i�i�i�i�x              �x�i�i�i�i�i�i
        ���i�x              �x�i��        
          �i�x              �x�i      ����
          �i�x              �x�i      ����
      ��  �i�x              �x�i  ��    ��
      ��  �i�x              �x�i  ��      
          �i�x              �x�i          
          �i�x              �x�i          
        ���i�x              �x�i��        
�i�i�i�i�i�i�x              �x�i�i�i�i�i�i
�w�w�w�w�w�w�}              �|�w�w�w�w�w�w
\n",]));
}

int closedoor(object me)
{
if(!me) return 0;//by pudon
tell_room(me,"\n  �F!!���@�n.. �K���S���_�ӤF�C \n");
 set("exits",([
 "north" : __DIR__"pearl_22",
 "south" : __DIR__"pearl_24",
 ]));
 set("item_desc",([
 "gate":"\n
�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w
�i�i�i�i�i�i�i�i�i�i�x�i�i�i�i�i�i�i�i�i�i    �W���٦��X�ӫ��s�C
                ���i�x�i��                     �z�w�s�w�s�w�{
                  �i�x�i      ����             �x���x���x���x
                  �i�x�i      ������           �u�w�q�w�q�w�t �ϥΤ�k:
              ��  �i�x�i  ��    ����           �x���x���x���x
              ��  �i�x�i  ��                   �u�w�q�w�q�w�t press [�Ʀr]
                  �i�x�i                       �x���x���x���x
                  �i�x�i                       �u�w�q�w�q�w�t
                ���i�x�i��                     �x���x���x���x
�i�i�i�i�i�i�i�i�i�i�x�i�i�i�i�i�i�i�i�i�i     �|�w�r�w�r�w�}
�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w
\n",
]));
return 1;
}
