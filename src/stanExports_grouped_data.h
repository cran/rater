// Generated by rstantools.  Do not edit by hand.

/*
    rater is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    rater is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with rater.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_grouped_data_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_grouped_data");
    reader.add_event(43, 41, "end", "model_grouped_data");
    return reader;
}
#include <stan_meta_header.hpp>
class model_grouped_data
  : public stan::model::model_base_crtp<model_grouped_data> {
private:
        int N;
        int K;
        int J;
        std::vector<double> tally;
        std::vector<std::vector<int> > key;
        vector_d alpha;
        std::vector<std::vector<vector_d> > beta;
public:
    model_grouped_data(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_grouped_data(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_grouped_data_namespace::model_grouped_data";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 1);
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            check_greater_or_equal(function__, "K", K, 1);
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "J", "int", context__.to_vec());
            J = int(0);
            vals_i__ = context__.vals_i("J");
            pos__ = 0;
            J = vals_i__[pos__++];
            check_greater_or_equal(function__, "J", J, 1);
            current_statement_begin__ = 5;
            validate_non_negative_index("tally", "N", N);
            context__.validate_dims("data initialization", "tally", "double", context__.to_vec(N));
            tally = std::vector<double>(N, double(0));
            vals_r__ = context__.vals_r("tally");
            pos__ = 0;
            size_t tally_k_0_max__ = N;
            for (size_t k_0__ = 0; k_0__ < tally_k_0_max__; ++k_0__) {
                tally[k_0__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 6;
            validate_non_negative_index("key", "N", N);
            validate_non_negative_index("key", "J", J);
            context__.validate_dims("data initialization", "key", "int", context__.to_vec(N,J));
            key = std::vector<std::vector<int> >(N, std::vector<int>(J, int(0)));
            vals_i__ = context__.vals_i("key");
            pos__ = 0;
            size_t key_k_0_max__ = N;
            size_t key_k_1_max__ = J;
            for (size_t k_1__ = 0; k_1__ < key_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < key_k_0_max__; ++k_0__) {
                    key[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            size_t key_i_0_max__ = N;
            size_t key_i_1_max__ = J;
            for (size_t i_0__ = 0; i_0__ < key_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < key_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "key[i_0__][i_1__]", key[i_0__][i_1__], 1);
                    check_less_or_equal(function__, "key[i_0__][i_1__]", key[i_0__][i_1__], K);
                }
            }
            current_statement_begin__ = 7;
            validate_non_negative_index("alpha", "K", K);
            context__.validate_dims("data initialization", "alpha", "vector_d", context__.to_vec(K));
            alpha = Eigen::Matrix<double, Eigen::Dynamic, 1>(K);
            vals_r__ = context__.vals_r("alpha");
            pos__ = 0;
            size_t alpha_j_1_max__ = K;
            for (size_t j_1__ = 0; j_1__ < alpha_j_1_max__; ++j_1__) {
                alpha(j_1__) = vals_r__[pos__++];
            }
            check_greater_or_equal(function__, "alpha", alpha, 0);
            current_statement_begin__ = 8;
            validate_non_negative_index("beta", "K", K);
            validate_non_negative_index("beta", "J", J);
            validate_non_negative_index("beta", "K", K);
            context__.validate_dims("data initialization", "beta", "vector_d", context__.to_vec(J,K,K));
            beta = std::vector<std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> > >(J, std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> >(K, Eigen::Matrix<double, Eigen::Dynamic, 1>(K)));
            vals_r__ = context__.vals_r("beta");
            pos__ = 0;
            size_t beta_j_1_max__ = K;
            size_t beta_k_0_max__ = J;
            size_t beta_k_1_max__ = K;
            for (size_t j_1__ = 0; j_1__ < beta_j_1_max__; ++j_1__) {
                for (size_t k_1__ = 0; k_1__ < beta_k_1_max__; ++k_1__) {
                    for (size_t k_0__ = 0; k_0__ < beta_k_0_max__; ++k_0__) {
                        beta[k_0__][k_1__](j_1__) = vals_r__[pos__++];
                    }
                }
            }
            size_t beta_i_0_max__ = J;
            size_t beta_i_1_max__ = K;
            for (size_t i_0__ = 0; i_0__ < beta_i_0_max__; ++i_0__) {
                for (size_t i_1__ = 0; i_1__ < beta_i_1_max__; ++i_1__) {
                    check_greater_or_equal(function__, "beta[i_0__][i_1__]", beta[i_0__][i_1__], 0);
                }
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 12;
            validate_non_negative_index("pi", "K", K);
            num_params_r__ += (K - 1);
            current_statement_begin__ = 13;
            validate_non_negative_index("theta", "K", K);
            validate_non_negative_index("theta", "J", J);
            validate_non_negative_index("theta", "K", K);
            num_params_r__ += (((K - 1) * J) * K);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_grouped_data() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 12;
        if (!(context__.contains_r("pi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable pi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("pi");
        pos__ = 0U;
        validate_non_negative_index("pi", "K", K);
        context__.validate_dims("parameter initialization", "pi", "vector_d", context__.to_vec(K));
        Eigen::Matrix<double, Eigen::Dynamic, 1> pi(K);
        size_t pi_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            pi(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.simplex_unconstrain(pi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable pi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 13;
        if (!(context__.contains_r("theta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable theta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("theta");
        pos__ = 0U;
        validate_non_negative_index("theta", "K", K);
        validate_non_negative_index("theta", "J", J);
        validate_non_negative_index("theta", "K", K);
        context__.validate_dims("parameter initialization", "theta", "vector_d", context__.to_vec(J,K,K));
        std::vector<std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> > > theta(J, std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> >(K, Eigen::Matrix<double, Eigen::Dynamic, 1>(K)));
        size_t theta_j_1_max__ = K;
        size_t theta_k_0_max__ = J;
        size_t theta_k_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < theta_j_1_max__; ++j_1__) {
            for (size_t k_1__ = 0; k_1__ < theta_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < theta_k_0_max__; ++k_0__) {
                    theta[k_0__][k_1__](j_1__) = vals_r__[pos__++];
                }
            }
        }
        size_t theta_i_0_max__ = J;
        size_t theta_i_1_max__ = K;
        for (size_t i_0__ = 0; i_0__ < theta_i_0_max__; ++i_0__) {
            for (size_t i_1__ = 0; i_1__ < theta_i_1_max__; ++i_1__) {
                try {
                    writer__.simplex_unconstrain(theta[i_0__][i_1__]);
                } catch (const std::exception& e) {
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable theta: ") + e.what()), current_statement_begin__, prog_reader__());
                }
            }
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 12;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> pi;
            (void) pi;  // dummy to suppress unused var warning
            if (jacobian__)
                pi = in__.simplex_constrain(K, lp__);
            else
                pi = in__.simplex_constrain(K);
            current_statement_begin__ = 13;
            std::vector<std::vector<Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> > > theta;
            size_t theta_d_0_max__ = J;
            size_t theta_d_1_max__ = K;
            theta.resize(theta_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < theta_d_0_max__; ++d_0__) {
                theta[d_0__].reserve(theta_d_1_max__);
                for (size_t d_1__ = 0; d_1__ < theta_d_1_max__; ++d_1__) {
                    if (jacobian__)
                        theta[d_0__].push_back(in__.simplex_constrain(K, lp__));
                    else
                        theta[d_0__].push_back(in__.simplex_constrain(K));
                }
            }
            // transformed parameters
            current_statement_begin__ = 17;
            validate_non_negative_index("log_p_z", "K", K);
            validate_non_negative_index("log_p_z", "N", N);
            std::vector<Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> > log_p_z(N, Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1>(K));
            stan::math::initialize(log_p_z, DUMMY_VAR__);
            stan::math::fill(log_p_z, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 19;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 20;
                stan::model::assign(log_p_z, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            stan::math::log(pi), 
                            "assigning variable log_p_z");
                current_statement_begin__ = 21;
                for (int j = 1; j <= J; ++j) {
                    current_statement_begin__ = 22;
                    for (int k = 1; k <= K; ++k) {
                        current_statement_begin__ = 23;
                        stan::model::assign(log_p_z, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), 
                                    (get_base1(get_base1(log_p_z, i, "log_p_z", 1), k, "log_p_z", 2) + stan::math::log(get_base1(get_base1(get_base1(theta, j, "theta", 1), k, "theta", 2), get_base1(get_base1(key, i, "key", 1), j, "key", 2), "theta", 3))), 
                                    "assigning variable log_p_z");
                    }
                }
            }
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 17;
            size_t log_p_z_k_0_max__ = N;
            size_t log_p_z_j_1_max__ = K;
            for (size_t k_0__ = 0; k_0__ < log_p_z_k_0_max__; ++k_0__) {
                for (size_t j_1__ = 0; j_1__ < log_p_z_j_1_max__; ++j_1__) {
                    if (stan::math::is_uninitialized(log_p_z[k_0__](j_1__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: log_p_z" << "[" << k_0__ << "]" << "(" << j_1__ << ")";
                        stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable log_p_z: ") + msg__.str()), current_statement_begin__, prog_reader__());
                    }
                }
            }
            // model body
            current_statement_begin__ = 29;
            lp_accum__.add(dirichlet_log<propto__>(pi, alpha));
            current_statement_begin__ = 31;
            for (int j = 1; j <= J; ++j) {
                current_statement_begin__ = 32;
                for (int k = 1; k <= K; ++k) {
                    current_statement_begin__ = 33;
                    lp_accum__.add(dirichlet_log<propto__>(get_base1(get_base1(theta, j, "theta", 1), k, "theta", 2), get_base1(get_base1(beta, j, "beta", 1), k, "beta", 2)));
                }
            }
            current_statement_begin__ = 38;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 39;
                lp_accum__.add((get_base1(tally, i, "tally", 1) * log_sum_exp(get_base1(log_p_z, i, "log_p_z", 1))));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("pi");
        names__.push_back("theta");
        names__.push_back("log_p_z");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(K);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(J);
        dims__.push_back(K);
        dims__.push_back(K);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dims__.push_back(K);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_grouped_data_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> pi = in__.simplex_constrain(K);
        size_t pi_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            vars__.push_back(pi(j_1__));
        }
        std::vector<std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> > > theta;
        size_t theta_d_0_max__ = J;
        size_t theta_d_1_max__ = K;
        theta.resize(theta_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < theta_d_0_max__; ++d_0__) {
            theta[d_0__].reserve(theta_d_1_max__);
            for (size_t d_1__ = 0; d_1__ < theta_d_1_max__; ++d_1__) {
                theta[d_0__].push_back(in__.simplex_constrain(K));
            }
        }
        size_t theta_j_1_max__ = K;
        size_t theta_k_0_max__ = J;
        size_t theta_k_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < theta_j_1_max__; ++j_1__) {
            for (size_t k_1__ = 0; k_1__ < theta_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < theta_k_0_max__; ++k_0__) {
                    vars__.push_back(theta[k_0__][k_1__](j_1__));
                }
            }
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 17;
            validate_non_negative_index("log_p_z", "K", K);
            validate_non_negative_index("log_p_z", "N", N);
            std::vector<Eigen::Matrix<double, Eigen::Dynamic, 1> > log_p_z(N, Eigen::Matrix<double, Eigen::Dynamic, 1>(K));
            stan::math::initialize(log_p_z, DUMMY_VAR__);
            stan::math::fill(log_p_z, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 19;
            for (int i = 1; i <= N; ++i) {
                current_statement_begin__ = 20;
                stan::model::assign(log_p_z, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            stan::math::log(pi), 
                            "assigning variable log_p_z");
                current_statement_begin__ = 21;
                for (int j = 1; j <= J; ++j) {
                    current_statement_begin__ = 22;
                    for (int k = 1; k <= K; ++k) {
                        current_statement_begin__ = 23;
                        stan::model::assign(log_p_z, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), 
                                    (get_base1(get_base1(log_p_z, i, "log_p_z", 1), k, "log_p_z", 2) + stan::math::log(get_base1(get_base1(get_base1(theta, j, "theta", 1), k, "theta", 2), get_base1(get_base1(key, i, "key", 1), j, "key", 2), "theta", 3))), 
                                    "assigning variable log_p_z");
                    }
                }
            }
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t log_p_z_j_1_max__ = K;
                size_t log_p_z_k_0_max__ = N;
                for (size_t j_1__ = 0; j_1__ < log_p_z_j_1_max__; ++j_1__) {
                    for (size_t k_0__ = 0; k_0__ < log_p_z_k_0_max__; ++k_0__) {
                        vars__.push_back(log_p_z[k_0__](j_1__));
                    }
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_grouped_data";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t pi_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t theta_j_1_max__ = K;
        size_t theta_k_0_max__ = J;
        size_t theta_k_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < theta_j_1_max__; ++j_1__) {
            for (size_t k_1__ = 0; k_1__ < theta_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < theta_k_0_max__; ++k_0__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "theta" << '.' << k_0__ + 1 << '.' << k_1__ + 1 << '.' << j_1__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t log_p_z_j_1_max__ = K;
            size_t log_p_z_k_0_max__ = N;
            for (size_t j_1__ = 0; j_1__ < log_p_z_j_1_max__; ++j_1__) {
                for (size_t k_0__ = 0; k_0__ < log_p_z_k_0_max__; ++k_0__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "log_p_z" << '.' << k_0__ + 1 << '.' << j_1__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t pi_j_1_max__ = (K - 1);
        for (size_t j_1__ = 0; j_1__ < pi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t theta_j_1_max__ = (K - 1);
        size_t theta_k_0_max__ = J;
        size_t theta_k_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < theta_j_1_max__; ++j_1__) {
            for (size_t k_1__ = 0; k_1__ < theta_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < theta_k_0_max__; ++k_0__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "theta" << '.' << k_0__ + 1 << '.' << k_1__ + 1 << '.' << j_1__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t log_p_z_j_1_max__ = K;
            size_t log_p_z_k_0_max__ = N;
            for (size_t j_1__ = 0; j_1__ < log_p_z_j_1_max__; ++j_1__) {
                for (size_t k_0__ = 0; k_0__ < log_p_z_k_0_max__; ++k_0__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "log_p_z" << '.' << k_0__ + 1 << '.' << j_1__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_grouped_data_namespace::model_grouped_data stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
