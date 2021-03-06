#include <ansi.h>
#define LEFT_ARM 1
#define RIGHT_ARM 2
#define LEFT_LEG 4
#define RIGHT_LEG 8
#define DOLL_HEAD 16

inherit ITEM;
string long=@LONG
這是一具玲瓏有緻而造型逼真的假身軀，穿戴著一件粉紅色的衣裳，點
綴著白色的圓點，纖弱的小蠻腰更凸顯出豐滿的胸部。但這只是一具身軀而
已，還少了一顆頭、兩隻手和兩隻腳，或許你能找出失散的手腳，好好把她
組合(compose)成一個真正的假人樣吧。
LONG
;

string query_long()
{
        string msg;
        int state=query("compose_state");
        if(state==0) return "";
        msg=HIC"\n這個假身軀上已經裝有：";
        if(state & 1)   msg+=" 左臂";
        if(state & 2)   msg+=" 右臂";
        if(state & 4)   msg+=" 左腳";
        if(state & 8)   msg+=" 右腳";
        if(state & 16)  msg+=" 人頭";
        msg+="等器官了。\n"NOR;
        return msg;
}


void create()
{
        set_name("不知名的身軀",({"unknown body","body","DOLL_BODY"}));
        set_weight(100);
        set("unit","具");
        set("long",long   );
        set("compose_state",0);
          set("replica_ob",__DIR__"right-arm");
        setup();
}

void init()
{
        add_action("do_compose","compose");
}

int do_compose(string arg)
{
        int state;
        object com,me,doll;
        me=this_player();
        state=query("compose_state");

        if(!arg)
                return notify_fail("你想要組合什麼？\n");
        if(!objectp(com=present(arg,me)))
                return notify_fail("你身上並沒有這個東西。\n");
        if(com->id("DOLL_LEFT_ARM") ) // 左臂 1
        {
                if( state & 1 ) 
                        return notify_fail("這個假身軀已經裝有「左臂」了。\n");
                message_vision(CYN"$N輕巧巧把$n往假身軀的左肩膀下一擠一推，成功\地接上左臂了。\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+1);
        }
        else if(com->id("DOLL_RIGHT_ARM") ) // 右臂 2
        {
                if( state & 2 ) 
                        return notify_fail("這個假身軀已經裝有「右臂」了。\n");
                message_vision(CYN"$N輕巧巧把$n往假身軀的右肩膀下一擠一推，成功\地接上右臂了。\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+2);
        }
        else if(com->id("DOLL_LEFT_LEG") ) // 左腳 4
        {
                if( state & 4 ) 
                        return notify_fail("這個假身軀已經裝有「左腳」了。\n");
                message_vision(CYN"$N試著把$n往假身軀的下半身銜接，經過一番努力，成功\地接上左腳了。\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+4);
        }
        else if(com->id("DOLL_RIGHT_LEG") ) // 右腳 8
        {
                if( state & 8 ) 
                        return notify_fail("這個假身軀已經裝有「右腳」了。\n");
                message_vision(CYN"$N試著把$n往假身軀的下半身銜接，經過一番努力，成功\地接上右腳了。\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+8);
        }
        else if(com->id("DOLL_HEAD") ) // 頭 16
        {
                if( state & 16 ) 
                        return notify_fail("這個假身軀已經裝有「頭」了。\n");
                message_vision(CYN"$N輕輕地將$n不偏不移的裝置到假身軀的脖子上，成功\地接上假人頭了。\n"NOR,me,com);
                destruct(com);
                set("compose_state",state+16);
        }
        else
                message_vision(CYN"$N左拼右拼的，就是無法把"+ com->name()+CYN"裝到假身軀上。\n"NOR,me,com);

        set("long",long+query_long());

        if(query("compose_state")==31) { // 全部拼完了
                doll=new("/open/always/doll");
                if(objectp(com=present("undead_item",me))) {
                message_vision(HIY"當$N成功\拼湊完整具假人娃娃時........\n"NOR
                +HIW"假人忽然化做一陣輕煙，隨風飄散不見了.....\n"NOR,me);
                destruct(this_object());
                return 1;
                } 
                message_vision(HIY"當$N成功\拼湊完整具假人娃娃時........\n"NOR
                +HIW"娃娃的雙眼忽然調皮的眨了數下，深情款款的注視著$N，嘴裡說道："
                +HIW"「從此就讓我跟隨著你，保護著你吧..........」\n\n"NOR,me);
                doll->move(me);
        log_file("static/COMPOSE_DOLL",
                sprintf("%s(%s) on compose doll at  %s\n",
                me->name(1), geteuid(me),ctime(time()) ) );

                destruct(this_object());                
        }
        return 1;
}


