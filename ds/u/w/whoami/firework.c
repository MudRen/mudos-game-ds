#include <ansi.h>
inherit ITEM;


void create()
{
        set_name(HIY"��"NOR""YEL"��"NOR, ({ "firework" }) );
        set("long", @LONG
        
�o�O�@�ӷϤ�, �I�U��(fire_firework), �A�N�|��o�\�h�ֽ�C

�Ϊk�Gfire_firework <�r�y>
LONG);
  if(clonep() )
    set_default_object(__FILE__);
    else
    {
    set("base_unit", "��");
    set("value", 1500);
    set("base_value", 1000);
    set("base_weight", 100);
    set("needsc", 1000);
                set("unit", "��");
                }
        setup();
} 

void init()
{
        add_action("do_light","fire_firework");
}


int do_light(string s)
{
        string s1, s2, cmsg;

        switch (random(7))
        {
        case 0  : s1= HIR; s2= "��"; break;
        case 1  : s1= HIM; s2= "��"; break;
        case 2  : s1= HIY; s2= "��"; break;
        case 3  : s1= HIG; s2= "��"; break;
        case 4  : s1= HIB; s2= "��"; break;
        case 5  : s1= HIC; s2= "�C"; break;
        case 6  : s1= HIW; s2= "��"; break;
        default : s1= HIR; s2= "��";
        } 

        message_vision("$N�N�Ϥ��I��, �M�ᱻ��զ����t�a����@��C\n",
                this_player() );
        if (!s) cmsg = s1 + "\n\t�y�I���@�n�A�@�T���R��"+ s2 +
                "��Ϥ��b�ѪŤ��n�g�}�ӡC\n" + NOR;
        else cmsg = s1 + "\n\t�y�I���@�n�A�\\�h�T���R��"+ s2 +
                "��Ϥ��b�Ť��n�g�}�ӡA�w�w�ۤƦ��@�Ʀr�G\n\n\t"+s+"�C\n\n" + NOR;
        shout(cmsg);
        write(cmsg);
        CHANNEL_D->do_channel(this_player(), "sys","�I��F�Ϥ��C\n");
        destruct(this_object());

        return 1;
} 

