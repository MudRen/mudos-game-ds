#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("���q",({"ar show","show"}) );
        set("long","���q�@���C\n");
        set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�@");
                set("value",100);
        }
        setup();

}

void init()
{
        add_action("do_show","show");
    add_action("do_laugh","laugh");
}

int do_show()
{
        string msg="";
        msg += HIM"\n\t�߮Z�իռ۹D�G\n\n"NOR;
        msg += HIG"\t\t�Q�����v��x��A���i���H�W�V���C\n";
        msg += "\t\t�������Z�L����A���ʲM�N�۪�t�C\n\n"NOR;
        msg+="\t(����`���ʶ}�l�C)\n";
        message("system",msg,users());
        return 1;
}
int do_laugh()
{
    message("system", HIR"\n�_(Tmr)�]�H��  ��11�� �Ův�P�Ův�L�G�o�;԰��A�N���H�Y���B���C �A�Q�y�v(Acme)���ɤF�C\n"NOR, users());
}

