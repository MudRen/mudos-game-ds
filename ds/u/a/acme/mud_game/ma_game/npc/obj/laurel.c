#include <ansi.h>

inherit ITEM;

string *attr1 = ({"木","火","土","金","水"});
string *attr2 = ({"乾","坤","震","巽","離","兌","坎","艮"});
string *attr3 = ({"山","水","澤","火","風","雷","地","天"});
int *value = ({ 9,8,7,6,4,3,2,1 });
string *g_name= ({"wood","fire","mud","gold","water"});

int do_chop(string arg);
void delete();

void create()
{
        set_name("不死桂樹", ({ "laurel"}) );
        set("long",@LONG
這顆桂樹高五百多丈，又叫做「三百斧頭」，有耐心的人，心平氣和的砍三百斧
頭，就可以把它砍倒。沒有耐心的人，砍了也是白砍。(砍：chop)
LONG
);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(9999999);
                set("unit", "棵");
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
                return notify_fail("你現在沒有空。\n");

/***************************       Ds 用     *******************************/
        if( me->query("ap") < 20 )
                return notify_fail("你現在沒有力氣砍了。\n");
        me->receive_damage("ap", 20);
/***************************************************************************/

/***************************       At 用     *******************************
        if( me->query_stat("shu") < 20 )
                return notify_fail("你現在沒有力氣砍了。\n");
        me->consume_stat("shu", 20);
***************************************************************************/

        if( arg != this_object()->query("id") ) 
                return notify_fail("你要砍什麼東西？\n");

        if( this_object()->query("chop") > 299 )
                return notify_fail("這棵樹已經倒了。\n");

        if( me->query_temp("weapon") )
        {

/***************************       Ds 用     *******************************/
        wp=me->query_temp("weapon");
        while( ( i < strlen(wp->query("id"))-1 ) && ((wp->query("id"))[i]!=' ') ) i++;
        if( (wp->query("id"))[i+1..sizeof(wp->query("id"))-1] != "axe" && wp->query("id") != "axe" )
                return notify_fail("這種武器似乎不能拿來砍樹。\n");
/***************************************************************************/

/***************************       At 用     *******************************
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
        if( !wp ) return notify_fail("你必需拿把斧頭才能砍哦。\n");

        message_vision("$N舉起手中$n往桂樹猛力一砍！\n",me,wp);

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
                        drug->set("name","藥材-"+name);
                        drug->set_name("藥材-"+name , ({ g_name[x]+" drug","drug"}) );
//                        drug->move(environment(me));
                        drug->move(me);


                        tell_object(environment(me),"(結果在桂樹身上烙下深深的傷口，並掉落了一片藥材-"+name+"。)\n");
                }
                else return notify_fail("(結果什麼事都沒有發生！)\n");

                if( this_object()->query("chop") > 299 )
                {
                        tell_object(environment(me),"桂樹微微一傾，接著「喀∼啦∼」數聲，倒了！\n");
                        this_object()->set_name("(倒塌)不死桂樹", ({ "fall's tree" , "tree"}) );
                        this_object()->set("long","這顆桂樹高五百多丈，又叫做「三百斧頭」，有耐心的人，心平氣和的砍三百斧\n"
                                   "頭，就可以把它砍倒。沒有耐心的人，砍了也是白砍。(但已被砍倒)\n");
//                          call_out("delete",600);
                          call_out("delete",180);


                }
        }
        else tell_object(environment(me),"(但是桂樹的傷口又復原了！)\n");

        me->start_busy(1);

        return 1;
}
void delete()
{
        tell_object(environment(this_player()),"桂樹化成一陣輕煙不見了！\n");
        destruct(this_object());
}

