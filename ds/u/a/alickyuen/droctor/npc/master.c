#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�u�@�H��",({"official"}));
        set("gender", "�k��");
        set("long",@LONG
�L�O�F���ҽЪ��@��u�@�H���A�t�d��o�ҷӪ��u�@�C
LONG
        );
        set("level",10);                
        set("age",40);                  
 set("talk_reply","�A�n�ӽ��ҷӶܡH\n");
        set("inquiry/�ҷ�","�o�̼Ȯɥu���ѥӽ���ͪ��ҷӡC\n");
  set("inquiry/help",
        HIY"APPLY�@�@�[�J��ͤu�|\n"NOR);
       setup();
}
void init()
{
                add_action("do_apply","apply");
}
int do_apply(string arg)
{
        int i;
        object ob, me, pass;
        ob = this_object();
        me = this_player();
        message_vision("$N�Q�[�J�u"+ arg+ "�v�C\n",me); 
        if(!arg || arg!="���" )
                return notify_fail("�o�̨S���o�Ӥ��|�C\n");
if(me->query_skill("literate")<20) return notify_fail("�A���A�X����͡C\n");
if(pass=present("passport of doctor",me)) return notify_fail("�A�w�g������ҷӤF�C\n");      
        if(stringp(me->query("class1") ) )
                return notify_fail("�A�w�g�ѥ[���|�Ϊ����F�C\n");
        if(me->query_temp("get_pass") ) return notify_fail("�A�w�g������ҷӤF�C\n");
{
        command("nod");
 //       command("say �Ѳ{�b�}�l�A�K�O��ͤ��|���@���l�C");
pass=new(__DIR__"obj/doctor_pass"); //�}���Чﰵ/open/always
pass->move(me);
message_vision("�u�@�H�����F$n�@������ҷӡC\n");
        me->set_temp("get_pass");
me->set("class1","���"); //��o�y�K���|�X�{��pass��J��L����
        }               
        return 1;
}
