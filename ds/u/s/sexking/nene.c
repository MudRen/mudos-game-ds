#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�g�g",({"nene"}));
  set("long",HIC"�@����R�M�ª��֤k\n"NOR
             HIM"���o�u���������I...\n"NOR);
  set("attitude", "peaceful");
  set("age",16);
  set("gender","�k��");
  set("level",1);
  set("evil",-100);
  set("no_fight",1);
  set("no_more",1);
  set("chat_chance", 5);
  set("chat_msg", ({
 "�g�g�L���ۻ�:sexking�u�i�R\n"
 "�g�g��:�ګܷRsexking��...\n"
}));
  set("inquiry",([
  "�T��" : "34,23,31..�ݳo�ӷF����?\n",
  "����" : "158����..�ݳo�ӷF����?\n",
  "sexking" : "�L�O�ڪ��k�B�ͣ�...�A���n�ۭt�L��..\n",
  "�p����" : "�L�O�ڪ��k�B�ͣ�...�A���n�ۭt�L��..\n",
  "cominging" : "��..��ť�L��..�n���O�e�������Щl�H��..\n",
  "tmr" : "��������...�L�D�K�������Щl�H�v��...\n",
  "acme" : "�L�n���O���Z���п�H...�ܦh�k�ͭ˰l�L���ˤl...\n",
  "linjack" : "ť���D�@�ӥ~���ܦѤ��߫o�ܦ~�C���H...��\n",
  "wilfred" : "�@�ӫܰ��t���w��...�̭����ܦh�n�Ϊ�LPC,sexking���L�Q��wilfred��}�Ӭݣ�.\n",
  "luky" : "�ڤ�����....�n���O�@���ۤƦ��s�����]����...\n",
  "shengsan" : "�y�O��luky���W���j�]��..�� -_-\n",
]));
  setup();
}
void init()
{ 
add_action("hest","hest");; 
add_action("do_shout","shout");
add_action("do_kiss","kiss");
}
int hest(string str)
{ 
object me,ccc;
me=this_player();
if(!objectp(ccc=present("item",me) ) )
return notify_fail(HIR"ĵ�i.�L���������̤��o����C\n"NOR);
command(str);
  return 1; 
}
int do_shout(string arg)
{
        object me;
        me=this_player();
        if(arg!="�ڷR�p")
        {
                notify_fail("�A�n�sԣ��?\n");
                return 0;
        }
        if(this_player()->query("id") == "sexking")
        {
                message_vision(HIM"$N��g�g�j�n�s�X�G�u�ڷR�p!�v\n"NOR,me);
                command("blush sexking");
                command("kiss sexking");
                command("say �ڤ]�R�A�C");
        }
        else
        {
                message_vision(HIW"$N�j�n��g�g�s�X�G�u�ڷR�p!�v\n",me);
                command(HIC"say �ڤS���{�A�A�A�F���R��?�I�C"NOR);
             }       
        return 1;
}
int do_kiss(string arg)
{
        object me;
        me=this_player();
        if(arg!="nene")
        {
                notify_fail("�A�n�˽�?\n");
                return 0;
        }
        if(this_player()->query("id") == "sexking")
        {
                message_vision(HIM"$N�������k�F�@�U�g�g���y�U..�n���C��\n"NOR,me);
                command("blush sexking");
                command("say �A�u���ܦ��ۣ��C");
                 command("kiss sexking");
        }
        else
        {
                message_vision(HIW"$N���n�˩g�g�ɳQ�g�g�{�F�}�^�F�@��!\n",me);
                command(HIC"say ���Y�n�I�S���A�˨�I�C"NOR);
             }       
        return 1;
}


