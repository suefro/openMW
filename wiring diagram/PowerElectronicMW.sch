<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.7.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="degson">
<description>&lt;p&gt;&lt;b&gt;&lt;a href="http://www.degson.net/pcb_screw/"&gt;DEGSON PCB screws&lt;/a&gt;&lt;/b&gt;&lt;/p&gt;
&lt;ul&gt;&lt;li&gt;&lt;b&gt;DG306-5.0&lt;/b&gt; series - 5.0mm pitch&lt;/li&gt;&lt;li&gt;&lt;b&gt;DG350-3.5&lt;/b&gt; series - 3.5mm pitch&lt;/li&gt;&lt;/ul&gt;
&lt;p&gt;Dec 2010 Ivan A-R (&lt;a href="http://tuxotronic.org"&gt;tuxotronic.org&lt;/a&gt;)&lt;/p&gt;
&lt;p&gt;License &lt;a href="http://creativecommons.org/licenses/by-sa/3.0/"&gt;CC Attribution-ShareAlike 3.0 Unported
&lt;/a&gt;&lt;/p&gt;</description>
<packages>
<package name="DG350-3.5-02P">
<wire x1="-3.5" y1="3.4" x2="3.5" y2="3.4" width="0.127" layer="21"/>
<wire x1="3.5" y1="3.4" x2="3.5" y2="-3.4" width="0.127" layer="21"/>
<wire x1="3.5" y1="-3.4" x2="-3.5" y2="-3.4" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-3.4" x2="-3.5" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-1.905" x2="-3.5" y2="-1.4288" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-1.4288" x2="-3.5" y2="3.4" width="0.127" layer="21"/>
<wire x1="0.95" y1="-0.5" x2="2.25" y2="0.8" width="0.127" layer="51"/>
<wire x1="1.25" y1="-0.85" x2="2.6" y2="0.5" width="0.127" layer="51"/>
<wire x1="-2.55" y1="-0.5" x2="-1.25" y2="0.8" width="0.127" layer="51"/>
<wire x1="-2.25" y1="-0.85" x2="-0.9" y2="0.5" width="0.127" layer="51"/>
<wire x1="-3.5" y1="2.25" x2="3.5" y2="2.25" width="0.127" layer="51"/>
<wire x1="3.5" y1="-2.25" x2="-3.5" y2="-2.25" width="0.127" layer="51"/>
<wire x1="-2.0638" y1="-4.1275" x2="-1.7463" y2="-3.6513" width="0.127" layer="21"/>
<wire x1="-1.7463" y1="-3.6513" x2="-1.4288" y2="-4.1275" width="0.127" layer="21"/>
<wire x1="-1.4288" y1="-4.1275" x2="-2.0638" y2="-4.1275" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-1.905" x2="-3.81" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.81" y2="-1.4288" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-1.4288" x2="-3.5" y2="-1.4288" width="0.127" layer="21"/>
<wire x1="3.5" y1="1.905" x2="3.81" y2="1.905" width="0.127" layer="21"/>
<wire x1="3.81" y1="1.905" x2="3.81" y2="1.4288" width="0.127" layer="21"/>
<wire x1="3.81" y1="1.4288" x2="3.5" y2="1.4288" width="0.127" layer="21"/>
<circle x="1.75" y="0" radius="1" width="0.127" layer="51"/>
<circle x="-1.75" y="0" radius="1" width="0.127" layer="51"/>
<pad name="1" x="-1.75" y="0" drill="1" shape="long" rot="R90"/>
<pad name="2" x="1.75" y="0" drill="1" shape="long" rot="R90"/>
<text x="-2.54" y="3.81" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="-4.445" y="-3.81" size="1.016" layer="27" ratio="18" rot="R90">&gt;VALUE</text>
</package>
<package name="DG306-5.0-02P">
<wire x1="-5" y1="4.5" x2="5" y2="4.5" width="0.127" layer="21"/>
<wire x1="5" y1="4.5" x2="5" y2="-3.1" width="0.127" layer="21"/>
<wire x1="5" y1="-3.1" x2="-5" y2="-3.1" width="0.127" layer="21"/>
<wire x1="-5" y1="-3.1" x2="-5" y2="2.5" width="0.127" layer="21"/>
<wire x1="-5" y1="2.5" x2="-5" y2="3" width="0.127" layer="21"/>
<wire x1="-5" y1="3" x2="-5" y2="4.5" width="0.127" layer="21"/>
<wire x1="-5" y1="2.5" x2="-5.5" y2="2.5" width="0.127" layer="21"/>
<wire x1="-5.5" y1="2.5" x2="-5.5" y2="3" width="0.127" layer="21"/>
<wire x1="-5.5" y1="3" x2="-5" y2="3" width="0.127" layer="21"/>
<wire x1="-3.75" y1="-0.75" x2="-1.75" y2="1.25" width="0.127" layer="51"/>
<wire x1="-3.25" y1="-1.25" x2="-1.25" y2="0.75" width="0.127" layer="51"/>
<wire x1="1.25" y1="-0.75" x2="3.25" y2="1.25" width="0.127" layer="51"/>
<wire x1="1.75" y1="-1.25" x2="3.75" y2="0.75" width="0.127" layer="51"/>
<wire x1="-5" y1="2.5" x2="5" y2="2.5" width="0.127" layer="51"/>
<wire x1="5" y1="-2.5" x2="-5" y2="-2.5" width="0.127" layer="51"/>
<wire x1="-0.2" y1="1.8" x2="0.2" y2="1.8" width="0.127" layer="51"/>
<wire x1="0.2" y1="1.8" x2="0.2" y2="-1.8" width="0.127" layer="51"/>
<wire x1="0.2" y1="-1.8" x2="-0.2" y2="-1.8" width="0.127" layer="51"/>
<wire x1="-0.2" y1="-1.8" x2="-0.2" y2="1.8" width="0.127" layer="51"/>
<wire x1="-2.8138" y1="-3.8275" x2="-2.4963" y2="-3.3513" width="0.127" layer="21"/>
<wire x1="-2.4963" y1="-3.3513" x2="-2.1788" y2="-3.8275" width="0.127" layer="21"/>
<wire x1="-2.1788" y1="-3.8275" x2="-2.8138" y2="-3.8275" width="0.127" layer="21"/>
<circle x="-2.5" y="0" radius="1.5" width="0.127" layer="51"/>
<circle x="-2.5" y="0" radius="1.7" width="0.127" layer="51"/>
<circle x="2.5" y="0" radius="1.5" width="0.127" layer="51"/>
<circle x="2.5" y="0" radius="1.7" width="0.127" layer="51"/>
<circle x="-2.5" y="3.2" radius="0.5" width="0.127" layer="51"/>
<circle x="2.5" y="3.2" radius="0.5" width="0.127" layer="51"/>
<pad name="1" x="-2.5" y="0" drill="1.4" shape="long" rot="R90"/>
<pad name="2" x="2.5" y="0" drill="1.4" shape="long" rot="R90"/>
<text x="-2.5" y="5" size="1.27" layer="25" ratio="18">&gt;NAME</text>
<text x="0" y="-5" size="1.27" layer="27" ratio="18">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="KL">
<wire x1="0" y1="1.27" x2="2.54" y2="-1.27" width="0.254" layer="94"/>
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<text x="3.048" y="-0.889" size="1.778" layer="95">&gt;NAME</text>
<pin name="KL" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="DG3XX-02" prefix="X">
<description>&lt;b&gt;DG350-3.5-02P&lt;/b&gt;&lt;br/&gt;
&lt;b&gt;DG306-5.0-02P&lt;/b&gt;</description>
<gates>
<gate name="-1" symbol="KL" x="0" y="0"/>
<gate name="-2" symbol="KL" x="0" y="-5.08"/>
</gates>
<devices>
<device name="-3.5" package="DG350-3.5-02P">
<connects>
<connect gate="-1" pin="KL" pad="1"/>
<connect gate="-2" pin="KL" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-5.0" package="DG306-5.0-02P">
<connects>
<connect gate="-1" pin="KL" pad="1"/>
<connect gate="-2" pin="KL" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="switch">
<description>&lt;b&gt;Switches&lt;/b&gt;&lt;p&gt;
Marquardt, Siemens, C&amp;K, ITT, and others&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="RDT1034">
<description>&lt;b&gt;PUSH SWITCH&lt;/b&gt;&lt;p&gt;
www.radiohm.com</description>
<wire x1="-4.4" y1="4.85" x2="4.4" y2="4.85" width="0.2032" layer="21"/>
<wire x1="4.85" y1="4.4" x2="4.85" y2="-4.4" width="0.2032" layer="21"/>
<wire x1="4.4" y1="-4.85" x2="-4.4" y2="-4.85" width="0.2032" layer="21"/>
<wire x1="-4.85" y1="-4.4" x2="-4.85" y2="4.4" width="0.2032" layer="21"/>
<wire x1="-3.7" y1="4.15" x2="3.7" y2="4.15" width="0.2032" layer="21"/>
<wire x1="4.15" y1="3.7" x2="4.15" y2="-3.7" width="0.2032" layer="21"/>
<wire x1="3.7" y1="-4.15" x2="-3.7" y2="-4.15" width="0.2032" layer="21"/>
<wire x1="-4.15" y1="-3.7" x2="-4.15" y2="3.7" width="0.2032" layer="21"/>
<wire x1="-4.85" y1="4.4" x2="-4.4" y2="4.85" width="0.2032" layer="21"/>
<wire x1="-4.15" y1="3.7" x2="-3.7" y2="4.15" width="0.2032" layer="21"/>
<wire x1="4.85" y1="4.4" x2="4.4" y2="4.85" width="0.2032" layer="21"/>
<wire x1="4.15" y1="3.7" x2="3.7" y2="4.15" width="0.2032" layer="21"/>
<wire x1="4.85" y1="-4.4" x2="4.4" y2="-4.85" width="0.2032" layer="21"/>
<wire x1="4.15" y1="-3.7" x2="3.7" y2="-4.15" width="0.2032" layer="21"/>
<wire x1="-4.85" y1="-4.4" x2="-4.4" y2="-4.85" width="0.2032" layer="21"/>
<wire x1="-4.15" y1="-3.7" x2="-3.7" y2="-4.15" width="0.2032" layer="21"/>
<pad name="B" x="0.65" y="1.9" drill="0.8"/>
<pad name="A1" x="-3.175" y="0.635" drill="0.8"/>
<pad name="A" x="3.175" y="-0.635" drill="0.8"/>
<text x="-3.81" y="2.54" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.81" y="-3.81" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="TL3XPO">
<description>&lt;b&gt;TINY SWITCH&lt;/b&gt;&lt;p&gt;
Source: http://www2.produktinfo.conrad.com/datenblaetter/700000-724999/705152-da-01-de-Subminiaturschalter_TL_36YO.pdf</description>
<wire x1="-5.08" y1="2.54" x2="5.08" y2="2.54" width="0.2032" layer="21"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-2.54" width="0.2032" layer="21"/>
<wire x1="5.08" y1="-2.54" x2="-5.08" y2="-2.54" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="-2.54" x2="-5.08" y2="2.54" width="0.2032" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="0" y2="1.27" width="0.2032" layer="51"/>
<wire x1="-3.175" y1="-1.27" x2="0" y2="-1.27" width="0.2032" layer="51"/>
<wire x1="0" y1="1.27" x2="0" y2="-1.27" width="0.2032" layer="51" curve="-180"/>
<wire x1="-1.375" y1="1.275" x2="-1.35" y2="-1.3" width="0.2032" layer="51" curve="-273.242292"/>
<circle x="-3.175" y="0" radius="1.27" width="0.2032" layer="51"/>
<pad name="1" x="-2.54" y="0" drill="1.1" diameter="1.4224" shape="long" rot="R90"/>
<pad name="2" x="0" y="0" drill="1.1" diameter="1.4224" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="0" drill="1.1" diameter="1.4224" shape="long" rot="R90"/>
<text x="-5.08" y="3.175" size="1.778" layer="25">&gt;NAME</text>
<text x="-5.08" y="-5.08" size="1.778" layer="27">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="NORMOPEN2-1">
<wire x1="-2.54" y1="0" x2="-2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-1.27" y2="-2.54" width="0.2032" layer="94"/>
<wire x1="-1.27" y1="-2.54" x2="3.048" y2="-0.762" width="0.2032" layer="94"/>
<wire x1="3.048" y1="-2.032" x2="3.048" y2="-2.54" width="0.2032" layer="94"/>
<wire x1="3.048" y1="-2.54" x2="5.08" y2="-2.54" width="0.2032" layer="94"/>
<wire x1="0.762" y1="-1.524" x2="0.762" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="0.762" y1="-0.508" x2="0.762" y2="0.254" width="0.2032" layer="94"/>
<wire x1="0.762" y1="0.254" x2="0.762" y2="0.508" width="0.2032" layer="94"/>
<wire x1="0.762" y1="1.016" x2="0.762" y2="1.524" width="0.2032" layer="94"/>
<wire x1="1.27" y1="1.524" x2="0.762" y2="1.524" width="0.2032" layer="94"/>
<wire x1="0.762" y1="1.524" x2="0.254" y2="1.524" width="0.2032" layer="94"/>
<wire x1="0.254" y1="-0.254" x2="0.762" y2="0.254" width="0.1524" layer="94"/>
<wire x1="0.762" y1="0.254" x2="1.27" y2="-0.254" width="0.1524" layer="94"/>
<circle x="-2.54" y="-2.54" radius="0.508" width="0" layer="94"/>
<text x="-3.048" y="2.286" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.81" y="-5.588" size="1.778" layer="96">&gt;VALUE</text>
<pin name="A" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="A1" x="-5.08" y="-2.54" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="B" x="7.62" y="-2.54" visible="off" length="short" direction="pas" swaplevel="2" rot="R180"/>
</symbol>
<symbol name="U">
<wire x1="0" y1="-3.175" x2="0" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="-1.905" x2="-1.905" y2="3.175" width="0.254" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="2.54" x2="2.54" y2="3.175" width="0.254" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-1.27" y2="2.54" width="0.254" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-2.54" y2="3.175" width="0.254" layer="94"/>
<text x="5.08" y="-2.54" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="7.62" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="P" x="0" y="-5.08" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="S" x="2.54" y="5.08" visible="pad" length="short" direction="pas" rot="R270"/>
<pin name="O" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="RDT1034" prefix="S">
<description>&lt;b&gt;PUSH SWITCH&lt;/b&gt;&lt;p&gt;
www.radiohm.com</description>
<gates>
<gate name="G$1" symbol="NORMOPEN2-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RDT1034">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="B" pad="B"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TL36PO" prefix="S">
<description>&lt;b&gt;TINY SWITCH&lt;/b&gt; ON - ON&lt;p&gt;
Source: http://www2.produktinfo.conrad.com/datenblaetter/700000-724999/705152-da-01-de-Subminiaturschalter_TL_36YO.pdf</description>
<gates>
<gate name="BEF1" symbol="U" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TL3XPO">
<connects>
<connect gate="BEF1" pin="O" pad="1"/>
<connect gate="BEF1" pin="P" pad="2"/>
<connect gate="BEF1" pin="S" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="AC_IN" library="degson" deviceset="DG3XX-02" device="-5.0"/>
<part name="LIGHT_BULB" library="degson" deviceset="DG3XX-02" device="-5.0"/>
<part name="RELAY_ON/OFF" library="degson" deviceset="DG3XX-02" device="-5.0"/>
<part name="MW_TRANSFORMER" library="degson" deviceset="DG3XX-02" device="-5.0"/>
<part name="NO_DOOR_SW" library="switch" deviceset="RDT1034" device=""/>
<part name="NC_DOOR_SW" library="switch" deviceset="RDT1034" device=""/>
<part name="DOOR_SW" library="switch" deviceset="TL36PO" device=""/>
<part name="ROTATE_PLATE_MOTOR" library="degson" deviceset="DG3XX-02" device="-5.0"/>
<part name="RELAY_POWER" library="degson" deviceset="DG3XX-02" device="-5.0"/>
<part name="FAN_MOTOR" library="degson" deviceset="DG3XX-02" device="-5.0"/>
</parts>
<sheets>
<sheet>
<plain>
<text x="20.32" y="93.98" size="1.778" layer="91">L</text>
<text x="27.94" y="93.98" size="1.778" layer="91">N</text>
<text x="17.78" y="88.9" size="1.778" layer="91">There must be filter</text>
<text x="63.5" y="5.08" size="1.778" layer="91">connected arduino relay</text>
<text x="129.54" y="48.26" size="1.778" layer="91">connected arduino relay</text>
<text x="73.66" y="93.98" size="1.778" layer="91">Open door:
-lightbulb on
Close door:
-lightbulb off
Timer on:
-lightbulb on
-fan on
-timer on
-rotate plate on
-POWE and ON/OFF </text>
</plain>
<instances>
<instance part="AC_IN" gate="-1" x="22.86" y="96.52" rot="R90"/>
<instance part="AC_IN" gate="-2" x="30.48" y="96.52" rot="R90"/>
<instance part="LIGHT_BULB" gate="-1" x="20.32" y="73.66" rot="R180"/>
<instance part="LIGHT_BULB" gate="-2" x="20.32" y="68.58" rot="R180"/>
<instance part="RELAY_ON/OFF" gate="-1" x="73.66" y="30.48" rot="R270"/>
<instance part="RELAY_ON/OFF" gate="-2" x="78.74" y="30.48" rot="R270"/>
<instance part="MW_TRANSFORMER" gate="-1" x="104.14" y="76.2"/>
<instance part="MW_TRANSFORMER" gate="-2" x="104.14" y="81.28"/>
<instance part="NO_DOOR_SW" gate="G$1" x="48.26" y="86.36" smashed="yes">
<attribute name="NAME" x="42.672" y="88.646" size="1.778" layer="95"/>
</instance>
<instance part="NC_DOOR_SW" gate="G$1" x="55.88" y="71.12" smashed="yes" rot="R270">
<attribute name="NAME" x="58.166" y="79.248" size="1.778" layer="95" rot="R270"/>
</instance>
<instance part="DOOR_SW" gate="BEF1" x="55.88" y="45.72" smashed="yes">
<attribute name="NAME" x="60.96" y="38.1" size="1.778" layer="95" rot="R90"/>
</instance>
<instance part="ROTATE_PLATE_MOTOR" gate="-1" x="104.14" y="60.96"/>
<instance part="ROTATE_PLATE_MOTOR" gate="-2" x="104.14" y="66.04"/>
<instance part="RELAY_POWER" gate="-1" x="104.14" y="45.72"/>
<instance part="RELAY_POWER" gate="-2" x="104.14" y="50.8"/>
<instance part="FAN_MOTOR" gate="-1" x="104.14" y="33.02"/>
<instance part="FAN_MOTOR" gate="-2" x="104.14" y="38.1"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="AC_IN" gate="-1" pin="KL"/>
<pinref part="LIGHT_BULB" gate="-1" pin="KL"/>
<wire x1="22.86" y1="93.98" x2="22.86" y2="83.82" width="0.1524" layer="91"/>
<pinref part="NO_DOOR_SW" gate="G$1" pin="A1"/>
<wire x1="22.86" y1="83.82" x2="22.86" y2="73.66" width="0.1524" layer="91"/>
<wire x1="43.18" y1="83.82" x2="22.86" y2="83.82" width="0.1524" layer="91"/>
<junction x="22.86" y="83.82"/>
<pinref part="NO_DOOR_SW" gate="G$1" pin="A"/>
<wire x1="43.18" y1="86.36" x2="43.18" y2="83.82" width="0.1524" layer="91"/>
<junction x="43.18" y="83.82"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="AC_IN" gate="-2" pin="KL"/>
<wire x1="30.48" y1="93.98" x2="30.48" y2="63.5" width="0.1524" layer="91"/>
<pinref part="NC_DOOR_SW" gate="G$1" pin="B"/>
<wire x1="30.48" y1="63.5" x2="53.34" y2="63.5" width="0.1524" layer="91"/>
<pinref part="DOOR_SW" gate="BEF1" pin="O"/>
<wire x1="53.34" y1="50.8" x2="53.34" y2="63.5" width="0.1524" layer="91"/>
<junction x="53.34" y="63.5"/>
<pinref part="RELAY_ON/OFF" gate="-2" pin="KL"/>
<wire x1="78.74" y1="33.02" x2="78.74" y2="63.5" width="0.1524" layer="91"/>
<wire x1="78.74" y1="63.5" x2="53.34" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="DOOR_SW" gate="BEF1" pin="S"/>
<wire x1="58.42" y1="50.8" x2="73.66" y2="50.8" width="0.1524" layer="91"/>
<pinref part="RELAY_ON/OFF" gate="-1" pin="KL"/>
<wire x1="73.66" y1="50.8" x2="73.66" y2="40.64" width="0.1524" layer="91"/>
<pinref part="FAN_MOTOR" gate="-1" pin="KL"/>
<wire x1="73.66" y1="40.64" x2="73.66" y2="33.02" width="0.1524" layer="91"/>
<wire x1="101.6" y1="33.02" x2="88.9" y2="33.02" width="0.1524" layer="91"/>
<wire x1="88.9" y1="33.02" x2="88.9" y2="40.64" width="0.1524" layer="91"/>
<wire x1="88.9" y1="40.64" x2="73.66" y2="40.64" width="0.1524" layer="91"/>
<junction x="73.66" y="40.64"/>
<pinref part="RELAY_POWER" gate="-1" pin="KL"/>
<wire x1="101.6" y1="45.72" x2="88.9" y2="45.72" width="0.1524" layer="91"/>
<wire x1="88.9" y1="45.72" x2="88.9" y2="40.64" width="0.1524" layer="91"/>
<junction x="88.9" y="40.64"/>
<pinref part="ROTATE_PLATE_MOTOR" gate="-1" pin="KL"/>
<wire x1="101.6" y1="60.96" x2="88.9" y2="60.96" width="0.1524" layer="91"/>
<wire x1="88.9" y1="60.96" x2="88.9" y2="45.72" width="0.1524" layer="91"/>
<junction x="88.9" y="45.72"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="LIGHT_BULB" gate="-2" pin="KL"/>
<pinref part="DOOR_SW" gate="BEF1" pin="P"/>
<wire x1="22.86" y1="68.58" x2="22.86" y2="40.64" width="0.1524" layer="91"/>
<wire x1="22.86" y1="40.64" x2="55.88" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="FAN_MOTOR" gate="-2" pin="KL"/>
<wire x1="101.6" y1="38.1" x2="96.52" y2="38.1" width="0.1524" layer="91"/>
<pinref part="NO_DOOR_SW" gate="G$1" pin="B"/>
<pinref part="NC_DOOR_SW" gate="G$1" pin="A1"/>
<wire x1="55.88" y1="83.82" x2="55.88" y2="81.28" width="0.1524" layer="91"/>
<pinref part="NC_DOOR_SW" gate="G$1" pin="A"/>
<wire x1="55.88" y1="81.28" x2="55.88" y2="76.2" width="0.1524" layer="91"/>
<wire x1="55.88" y1="76.2" x2="53.34" y2="76.2" width="0.1524" layer="91"/>
<junction x="55.88" y="76.2"/>
<pinref part="MW_TRANSFORMER" gate="-2" pin="KL"/>
<wire x1="101.6" y1="81.28" x2="96.52" y2="81.28" width="0.1524" layer="91"/>
<junction x="55.88" y="81.28"/>
<pinref part="ROTATE_PLATE_MOTOR" gate="-2" pin="KL"/>
<wire x1="96.52" y1="81.28" x2="55.88" y2="81.28" width="0.1524" layer="91"/>
<wire x1="101.6" y1="66.04" x2="96.52" y2="66.04" width="0.1524" layer="91"/>
<wire x1="96.52" y1="66.04" x2="96.52" y2="81.28" width="0.1524" layer="91"/>
<junction x="96.52" y="81.28"/>
<wire x1="96.52" y1="38.1" x2="96.52" y2="66.04" width="0.1524" layer="91"/>
<junction x="96.52" y="66.04"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="MW_TRANSFORMER" gate="-1" pin="KL"/>
<wire x1="101.6" y1="76.2" x2="99.06" y2="76.2" width="0.1524" layer="91"/>
<pinref part="RELAY_POWER" gate="-2" pin="KL"/>
<wire x1="99.06" y1="76.2" x2="99.06" y2="50.8" width="0.1524" layer="91"/>
<wire x1="99.06" y1="50.8" x2="101.6" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
</compatibility>
</eagle>
