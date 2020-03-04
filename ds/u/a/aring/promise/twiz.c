//Query online wizards
//by moto and nokia
#include <ansi.h>
inherit ITEM;
void create()
{


       set_name(HIW""BLK"�u�WWIZ������"NOR, ({"wizlist machine", "machine"}));
        set_weight(1000);
        set("unit", "��");
        set("long", @LONG�����u�Wwiz
LONG);
        set("value", 99999);

        setup();
}


void init() 
{          
 add_action("do_twiz","twiz");
}

int do_twiz()
{
        int i = 0, idle;
        object *user, wizard;
        string status;

        user=users();

        printf(HIB"�w�w�w�w�w�w�w�w�w�w�w�w�}"HIY"Online Wizards List"HIB"�|�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR);

        foreach(wizard in user)
        {
                status = "";
                
                if(wizardp(wizard))
                {
                        i++;
                        idle = query_idle(wizard);
                        
                        if( in_input(wizard) )
                                status = HIM"(��J��) "NOR;
                        else if( in_edit(wizard) )
                                status += HIW"(�����) "NOR;
                        else if( idle > 60 )
                                status += sprintf(HIY"(�o�b %d ����)"NOR, idle / 60);
                        else
                                status = "";
                                
                        printf("%2d. ", i);
                        printf("%s�u%s�v", wizard->query("guild_rank"), wizard->query("nickname"));
                        printf("%s(%s)", wizard->query("name"), wizard->query("id"));
                        if( status != "" )
                                printf(HIM"  �ߧӥ[�J"HIY"�J���u�|"HIM"����"NOR" %s\n", status);
                        else
                                printf("\n");
                }
        }

        printf(HIB"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{"HIW"Total %2d Wizards Online"HIB"�z�w�w\n"NOR, i);

        return 1;
}

