## ---- include = FALSE---------------------------------------------------------
knitr::opts_chunk$set(
  collapse = TRUE,
  comment = "#>"
)

## ----setup--------------------------------------------------------------------
library(rater)

## ----show-long-data, echo = FALSE---------------------------------------------
long_data <- data.frame(
  item = c(1, 1, 2, 2, 3, 3), 
  rater = c(1, 2, 1, 2, 1, 2), 
  rating = c(3, 4, 2, 2, 2, 2)
)
knitr::kable(long_data)

## ----show-wide-data, echo = FALSE---------------------------------------------
wide_data <- data.frame(
  rater_1 = c(3, 2, 2), 
  rater_2 = c(4, 2, 2)
)
knitr::kable(wide_data)

## ----show-grouped-data, echo = FALSE------------------------------------------
grouped_data <- data.frame(
  data.frame(
    rater_1 = c(3, 2), 
    rater_2 = c(4, 2), 
    n = c(1, 2))
)

knitr::kable(grouped_data)

