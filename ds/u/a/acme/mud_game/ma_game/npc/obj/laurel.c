#include <ansi.h>

inherit ITEM;

string *attr1 = ({"��","��","�g","��","��"});
string *attr2 = ({"��","�[","�_","�S","��","�I","��","��"});
string *attr3 = ({"�s","��","�A","��","��","�p","�a","��"});
int *value = ({ 9,8,7,6,4,3,2,1 });
string *g_name= ({"wood","fire","mud","gold","water"});

int do_chop(string arg);
void delete();

void create()
{
        set_name("�����۾�", ({ "laurel"}) );
        set("long",@LONG
�o���۾𰪤��ʦh�V�A�S�s���u�T�ʩ��Y�v�A���@�ߪ��H�A�ߥ���M����T�ʩ�
�Y�A�N�i�H�⥦��ˡC�S���@�ߪ��H�A��F�]�O�լ�C(��Gchop)
LONG
);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(9999999);
                set("unit", "��");
                set("no_get",1);
                set("no_sac",1);
        }
        setup();
        enable_commands();
        set_living_name("ma_game");
}

void init()
{
        if( this_object()->query("chop") < 300 )
                add_action("do_chop","chop");
}

int do_chop(string arg)
{
        int i=0,j,x;
        string name="",str;
        object me=this_player(),*wps,wp,drug;

        if( me->is_busy() )
                return notify_fail("�A�{�b�S���šC\n");

/***************************       Ds ��     *******************************/
        if( me->query("ap") < 20 )
                return notify_fail("�A�{�b�S���O���F�C\n");
        me->receive_damage("ap", 20);
/***************************************************************************/

/***************************       At ��     *******************************
        if( me->query_stat("shu") < 20 )
                return notify_fail("�A�{�b�S���O���F�C\n");
        me->consume_stat("shu", 20);
***************************************************************************/

        if( arg != this_object()->query("id") ) 
                return notify_fail("�A�n�夰��F��H\n");

        if( this_object()->query("chop") > 299 )
                return notify_fail("�o�ʾ�w�g�ˤF�C\n");

        if( me->query_temp("weapon") )
        {

/***************************       Ds ��     *******************************/
        wp=me->query_temp("weapon");
        while( ( i < strlen(wp->query("id"))-1 ) && ((wp->query("id"))[i]!=' ') ) i++;
        if( (wp->query("id"))[i+1..sizeof(wp->query("id"))-1] != "axe" && wp->query("id") != "axe" )
                return notify_fail("�o�تZ�����G���ள�Ӭ��C\n");
/***************************************************************************/

/***************************       At ��     *******************************
                wps=values(me->query_temp("weapon"));
                i=sizeof(wps);
                while( i-- )
                {
                        if( (wps[i]->query("equipped"))[7..9] == "axe" )
                        {
                                wp=wps[i];
                                continue;       
                        }
                }
***************************************************************************/

        }
        if( !wp ) return notify_fail("�A���ݮ�����Y�~���@�C\n");

        message_vision("$N�|�_�⤤$n���۾�r�O�@��I\n",me,wp);

        if( random(100) > 50 )
        {
                add("chop",1);
                drug=new(__DIR__"drug.c");
                if( objectp(drug) )
                {
                        x=random(sizeof(attr1));
                        name+=attr1[x];
                        drug->set("attr1",x+1);
                        i=random(sizeof(attr2));
                        name+=attr2[i];
                        drug->set("attr2",value[i]);
                        i=random(sizeof(attr3));
                        name+=attr3[i];
                        drug->set("attr3",value[i]);
                        drug->set("name","�ħ�-"+name);
                        drug->set_name("�ħ�-"+name , ({ g_name[x]+" drug","drug"}) );
//                        drug->move(environment(me));
                        drug->move(me);


                        tell_object(environment(me),"(���G�b�۾𨭤W�O�U�`�`���ˤf�A�ñ����F�@���ħ�-"+name+"�C)\n");
                }
                else return notify_fail("(���G����Ƴ��S���o�͡I)\n");

                if( this_object()->query("chop") > 299 )
                {
                        tell_object(environment(me),"�۾�L�L�@�ɡA���ۡu�ء�ա�v���n�A�ˤF�I\n");
                        this_object()->set_name("(�˶�)�����۾�", ({ "fall's tree" , "tree"}) );
                        this_object()->set("long","�o���۾𰪤��ʦh�V�A�S�s���u�T�ʩ��Y�v�A���@�ߪ��H�A�ߥ���M����T�ʩ�\n"
                                   "�Y�A�N�i�H�⥦��ˡC�S���@�ߪ��H�A��F�]�O�լ�C(���w�Q���)\n");
//                          call_out("delete",600);
                          call_out("delete",180);


                }
        }
        else tell_object(environment(me),"(���O�۾𪺶ˤf�S�_��F�I)\n");

        me->start_busy(1);

        return 1;
}
void delete()
{
        tell_object(environment(this_player()),"�۾�Ʀ��@�}���Ϥ����F�I\n");
        destruct(this_object());
}

