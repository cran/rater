## ----setup, include = FALSE---------------------------------------------------
knitr::opts_chunk$set(
  comment = "#>"
)

## ----package-load-------------------------------------------------------------
# Load the rater package.
library(rater)

# Access the 'anesthesia' data set.
data("anesthesia")

## ----one-row------------------------------------------------------------------
anesthesia[20, ]

## ---- inference, warnings = FALSE, message = FALSE----------------------------
fit <- rater(anesthesia, "dawid_skene", chains = 1, verbose = FALSE)

## ----optim-fit----------------------------------------------------------------
optim_fit <- rater(anesthesia, "dawid_skene", method = "optim")

## ----plot-pi, fig.width = 6, fig.height = 4-----------------------------------
plot(fit, pars = "pi")

## ----plot-theta, fig.width = 6, fig.height = 4--------------------------------
plot(fit, pars = "theta")

## ----plot-z, fig.width = 6, fig.height = 8------------------------------------
plot(fit, pars = "latent_class")

## ----point-estimates----------------------------------------------------------
# Extract all parameters.
all_parameters <- point_estimate(fit)

# Extract only the 'pi' parameter. 
point_estimate(fit, pars = "pi")

