<GameProjectFile>
  <PropertyGroup Type="Scene" Name="LogoALi" ID="8bd41c09-ba99-47ab-bdb5-80dfa31edccd" Version="2.3.0.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="160" Speed="1.0000">
        <Timeline ActionTag="1607477169" Property="CColor">
          <ColorFrame FrameIndex="0" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
          <ColorFrame FrameIndex="120" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
          <ColorFrame FrameIndex="160" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
        </Timeline>
        <Timeline ActionTag="1607477169" Property="FrameEvent">
          <EventFrame FrameIndex="160" Tween="False" Value="frameEnd" />
        </Timeline>
        <Timeline ActionTag="1607477169" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="120" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="160" Value="33">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="12" ctype="GameNodeObjectData">
        <Size X="1280.0000" Y="720.0000" />
        <Children>
          <AbstractNodeData Name="Image_bg" ActionTag="1189611143" Tag="15" IconVisible="False" Scale9Width="1280" Scale9Height="720" ctype="ImageViewObjectData">
            <Size X="1280.0000" Y="720.0000" />
            <Children>
              <AbstractNodeData Name="Panel_logo" ActionTag="1607477169" Tag="17" Alpha="60" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="640.0000" RightMargin="640.0000" TopMargin="345.6000" BottomMargin="374.4000" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" ctype="PanelObjectData">
                <Size />
                <Children>
                  <AbstractNodeData Name="Image_ali" ActionTag="-1508460935" Tag="16" FrameEvent="frameEnd" IconVisible="False" LeftMargin="-401.5000" RightMargin="38.5000" TopMargin="-51.5000" BottomMargin="-51.5000" Scale9Width="363" Scale9Height="103" ctype="ImageViewObjectData">
                    <Size X="363.0000" Y="103.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="-220.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize />
                    <FileData Type="PlistSubImage" Path="logo_ali.png" Plist="img/login/login.plist" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Image_titan" ActionTag="-1653375803" Tag="17" IconVisible="False" LeftMargin="51.5000" RightMargin="-368.5000" TopMargin="-91.0000" BottomMargin="-91.0000" Scale9Width="317" Scale9Height="182" ctype="ImageViewObjectData">
                    <Size X="317.0000" Y="182.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="210.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize />
                    <FileData Type="PlistSubImage" Path="logo_titan.png" Plist="img/common/ui.plist" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="640.0000" Y="374.4000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5200" />
                <PreSize />
                <SingleColor A="255" R="150" G="200" B="255" />
                <FirstColor A="255" R="150" G="200" B="255" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="img/common/bg/splash_bg.png" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>