#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"��g���p��"NOR,({ "The crzay child","child"}));
        set("long",@LONG
�@��W�ŧ�g���p��,���۶ø����n��g,���O�L�n����
�F�Ǩƫܵ۫檺�ˤl�C
LONG
);
        set("level", 1);
        set("age",5);
        set("chat_chance", 10);
        set("chat_msg", ({
 "��g���p�ħ�g����:�����F!�u�������F!"
 "��g���p�ħ�g����:���J�F!sexking�|���ڧ�������~~"
}));
        set("inquiry",([
  "shit" : "�O�@�ӫܺ}�G���K�K��~����������...\n",
  "�����K�K" : "�O�@�ӫܺ}�G���K�K��~����������...\n",
  "gold-shit" : "�O�@�ӫܺ}�G���K�K��~����������...\n",
  "sexking" : "�ڬO�L���B�ͣ�~~�ڭ̳��ܧ�g��...\n",
]));

        setup();
        add_money("coin",150);
        carry_object(__DIR__"sk3");
}

int talk_action(object me)
{
        object ob;
        message_vision(HIC"��g���p�Ĺ�$N��:���J�F~~�ڧ�sexking�߷R�������K�K(gold shit)���˥�F�C\n"NOR,me);
        return 1;
}

int accept_object(object who, object ob)
{
        object sex,a,sk3;
        sex = this_object();
        sk3 =new(__DIR__"sk3");
        if( ob->query("id")!="gold-shit" || query_temp("gold-shit") ) return 0;
        command("say �z~~�o���O�����K�K��?�ڧ��F�I�ڧ��F�I\n");
        command("say ���°�!");
        command("say ��~�e�A�@�Ӥk�H�̷R���Ƨ��~~sk3~��@�ڪ���§..^^");
        sk3->move(who);
        set_temp("gold-shit",1);
        tell_object(who,HIR"�A��Mı�o�n�����N�P,�����������F�_�ӡC\n"NOR);
        call_out("delay",600,this_object());
        set("long",HIC"�@�Ӷ}�}�ߤ߻D�۫K�K���p��\n"NOR);
        set_name(HIC"��g���D�K�K���p��"NOR,({ "The shit child","child"}));
        set("chat_chance", 10);
        set("chat_msg", ({
    "��g���p�Ķ}�߻�:�o�U���F�����K�K�N���|�Qsexking�|�F."
     }));
return 1;
}
void delay(object sex)
{
delete_temp("gold-shit");
             set("long",@LONG
�@��W�ŧ�g���p��,���۶ø����n��g,���O�L�n����
�F�Ǩƫܵ۫檺�ˤl�C
LONG
);
        return;
}

        
