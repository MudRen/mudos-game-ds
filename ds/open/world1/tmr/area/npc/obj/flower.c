inherit ITEM;

void create()
{
        set_name("夜落金錢",({"night_money flower","flower"}) );
        set_weight(200);
        set("long",
"一株金黃色的花卉，帶有九片亮黃花瓣，呈扇形分佈，亭亭淨直，神聖\n"
"不可侵犯的模樣，卻又略帶幾分羞澀，實是奇花一朵。\n"
        );
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",200);
        }
        setup();
}


