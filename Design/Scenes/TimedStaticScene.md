> Scene depicts a static graphic or group of graphics that fade into view, remain for a specified duration and then fade out of view

- Parameters
  - duration
  - fadeInSpeed
  - fadeOutSpeed
  - graphics

```mermaid
graph TD
  %% Nodes
    start([Start])
    finish([End])
    fadeIn(Fade In)
    optionSkip[/Skip/]
    graphicDisplay(Display Graphic for X Seconds)
    fadeOut(Fade Out)
  %% Links
    start --> fadeIn --> graphicDisplay --> fadeOut --> finish
    fadeIn --> optionSkip --> finish
```