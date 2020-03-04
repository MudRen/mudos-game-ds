#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�q�l�����y"NOR, ({ "monstor ball","ball" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@�Ӯ���(catch)�ʪ��Ϊ��q�l�����y�C\n"
"�q�l�����y�O�S�򥻬[�c���A�A�ݪ��ɭԤ]�u�O�ਣ��p�ʪ��A\n"
"�����O�Ѭ��~�u�����u�����@�ӹq�l�����y�ӧ�ʪ��x�_�ӡC\n");
                set("unit", "��");
                set("value",0);
// set("material","rubber");  �q�lŢ�O�S�򥻬[�c��,�ݤW�h�]�u�O�o�@���p�ʪ�,
// �����O�Ѭ��~�u���������u�����@�ӹq�lŢ�ӧ�ʪ���_��
        }
        setup();
}

void init()
{ 
        add_action("do_catch","catch");
}

int do_catch(string arg)
{
        object me,obj;
        me=this_player();
        if( !arg ) return notify_fail("�A�Q�����֡H\n");
   if(me->is_busy() ) return notify_fail("�A�����ۡC\n");
        if(!objectp(obj = present(arg, environment(me)))) return notify_fail("�o�̨S���o�تF��C\n");
        if( !obj->is_character() || obj->is_corpse() ) return notify_fail("�A�u�ஷ�������ͪ��C\n");
         if(userp(obj)) return notify_fail("�A������������a�@�C\n");
        message_vision("$N�@�⮳�_�q�l�����y�A�@��ǳƥh���$n�C\n",me,obj);
if (arg != "wildanimal") 
        {
                message_vision("�o���O�A�n�������ʪ��C\n"NOR,me,obj);
        }
        else {
        if( random(100) > 70 )
	{
message_vision("$N�@���$n��F�i�q�l�����y�C\n",me,obj);
                me->add("Find_An/animal",1);
                set("long", "�o�O�@�Ӯ���(catch)�ʪ��Ϊ��q�l�����y�C\n"
"�q�l�����y�O�S�򥻬[�c���A�A�ݪ��ɭԤ]�u�O�ਣ��p�ʪ��A\n"
"�����O�Ѭ��~�u�����u�����@�ӹq�l�����y�ӧ�ʪ��x�_�ӡC\n"
        "�A�ݨ��q�lŢ�W�g�ۤ@�Ӧr�G\n"
YEL"�@�@�@�@�@�@�@�@�@�U�СССССU\n"NOR
YEL"�@�@�@�@�@�@�@�@�@�@�@�@"+me->query("Find_An/animal")+"�@�@\n"NOR
YEL"�@�@�@�@�@�@�@�@�@�U�СССССU\n"NOR
        );
                destruct(obj);
	}
	else
	{
	message_vision("�p�ʪ���ı��$N���|�ʡA�b�F�@�|�C\n",me);
	me->start_busy(1);
	}
        }
        return 1;
}
