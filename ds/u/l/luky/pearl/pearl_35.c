#include <ansi.h>
inherit ROOM;
int check_killer();
void create()
{
set("short", "[1;36m�Կp�����][m");
set("long",@LONG

  �o�����]�����v�Q���y�[�M�\�]�]��������C���]����
��˵��������b�d�i�˦۬��ȫȪA��(service)�C                       
       �z�s�{          �z�s�{                  �j
       �u�q�t          �u�t�x                  �j
       �|�r�}          �|�r�}[1;32m�\[m   �š�         �j
��                         [1;32m��[1;31m��[1;32m��[m ��  ��       �j
����    �z�w�w�w�{          [1;32m/_|_*[m �i��  ��___O_�j
�����šâx[1;33m�ФW��[m�x�áááá� \_/�â��i��  ��/Y\��
�â����Ţ|�w�s�w�}                  ���i��  �áááâ�
  �â���    �r                        ���i�i�i�i�i�i�i
    �â�                                ���i�i�i�i�i�i
�áá�
LONG
);
set("item_desc", ([
"window":@NOTE
[1;32m���~�H�ӤH�����A�c���@�T�M���־x�����H�C[m
NOTE
]) );        
 set("light",1);
  set("no_clean_up", 0);
 set("objects",([
 __DIR__"npc/lamuza":1,
 ]));
 set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"pearl_8",
  "up" : __DIR__"pearl_38", 
 ]));
 setup();
}
void init()
{
 check_killer();
}
int check_killer()
{
 object me;
 me=this_player();
 if(me->query_temp("killer"))
 {
  message_vision(HIR"\n���]����j�|: $N����i��!!\n\n �ڭ̳o�̤��w����H�g!!!\n\n"NOR,me);
  me->move(__DIR__"pearl_8");
  message_vision(HIY"\n$N�Q���]�����F�X��..\n\n"NOR,me);
  return 0;
 }
 return 1;
}