#include <ansi.h>
inherit NPC;
void create()
{
       set_name("蘇隸文",({"Dr.Sulivan","doctor","sulivan"}));
       set("long",@LONG
一個東方面孔的男子，穿著常見的旅行者衣著，頭髮在腦後束成一束
，翹著二郎腿斜坐在吧臺前面，左手拿著一大杯麥酒，右手捧著一本厚書
在讀，當他看見你時，對你笑了一笑，看來是個親切的好人。事實上這位
就是有名的冒險者Dr.Sulivan，傳說他是從東方來的，在西方大陸旅行，
踏遍了幾乎整個世界，也因此熟知了許多傳說與典故，你可以請他說說那
些故事，只要有一杯麥酒，他一定會很樂意的。
LONG);
       set("gender","男性");
       set("age", 27);
       set("level", 77);
       set("nickname",HIW"Dr."NOR);
       set("attitude", "peaceful");

       set("chat_chance", 3);
       set("chat_msg", ({
            "蘇隸文拿起麥酒咕嚕咕嚕的喝了一大口。\n",
            "蘇隸文將把書翻到下一頁，又津津有味的讀了起來。\n",
            "蘇隸文把書闔了起來，吁了一大口氣。\n"
           }));
       set("talk_reply","想聽我說故事嗎？請我一杯(have_a_drink)我就告訴你。:D~\n");
    
        setup();        
}
void init()
{
        ::init();
        add_action("do_story","have_a_drink");
}
int do_story()
{       
        string story="";
        int i,j,max;
        max = 1;
	while(read_file(__DIR__"obj/west_story.txt", max, 1))max++;//計算總行數(計算後會多3)
        i = random(max-4)+1;//從所有行數中隨意挑一行
        //決定從哪一行開頭
        while(strlen(read_file(__DIR__"obj/west_story.txt",i,1)) > 1)
        { 
                i++;
                if (i >= (max-3)) i=1;// 當i碰到結尾時，重新計算        
        }
        //決定結束的地方
        j = i+1;//從標記下一行算起
        while(strlen(read_file(__DIR__"obj/west_story.txt",j,1)) > 1)
        {
                j++;
        }

        //輸入資料到story
        story += HIY"蘇隸文喝了一口麥酒，以朗誦的語氣說道﹕\n"NOR;
        story += HIC+read_file(__DIR__"obj/west_story.txt",i+1,j-i)+NOR;
        //輸出給player看
        this_player()->start_more(story);
        return 1;

}
